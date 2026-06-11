/* 
 * Project: AtCoder Beginners Contest 175 A - Rainy Season
 * Author: toms74209200 <https://github.com/toms74209200>
 *
 * Created on 2020/08/29
 * Copyright (c) 2020 toms74209200
 * 
 * This software is released under the MIT License.
 * http://opensource.org/licenses/mit-license.php
 */
#include <cstdio>
#include <cstdint>
#include <algorithm>
using namespace std;

int main() {

    int8_t c;
    uint32_t cnt = 0;
    uint32_t max_cnt = 0;
    for (int i=0;i<3;i++) {
        scanf("%c", &c);
        if (c == 'R') {
            cnt++;
        } else {
            cnt = 0;
        }
        max_cnt = max(max_cnt,cnt);
    }
    printf("%d\n", max_cnt);

}