/*
 * This file is part of Libav.
 *
 * Libav is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * Libav is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with Libav; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA
 */

/**
 * @file
 * null video filter
 */

#include "libavutil/internal.h"
#include "avfilter.h"
#include "internal.h"
#include "video.h"

static const AVFilterPad avfilter_vf_null_inputs[] = {
    {
        .name             = "default",
        .type             = AVMEDIA_TYPE_VIDEO,
        .get_video_buffer = ff_null_get_video_buffer,
    },
    { NULL }
};

static const AVFilterPad avfilter_vf_null_outputs[] = {
    {
        .name = "default",
        .type = AVMEDIA_TYPE_VIDEO,
    },
    { NULL }
};

AVFilter ff_vf_null = {
    .name      = "null",
    .description = NULL_IF_CONFIG_SMALL("Pass the source unchanged to the output."),

    .priv_size = 0,

    .inputs    = avfilter_vf_null_inputs,

    .outputs   = avfilter_vf_null_outputs,
};
