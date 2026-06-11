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
using namespace std;

int main() {

    char c;
    unsigned int cnt = 0;
    unsigned int max_cnt = 0;
    for (int i=0;i<3;i++) {
        scanf("%c", &c);
        if (c == 'R') {
            cnt++;
        } else {
            cnt = 0;
        }
        if (cnt > max_cnt)
            max_cnt = cnt;
    }
    printf("%d\n", max_cnt);

}