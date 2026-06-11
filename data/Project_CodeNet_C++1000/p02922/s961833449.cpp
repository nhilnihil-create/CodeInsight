/* 
 * Project: AtCoder Beginners Contest 139 B - Power Socket
 * Author: toms74209200 <https://github.com/toms74209200>
 *
 * Created on 2020/08/25
 * Copyright (c) 2020 toms74209200
 * 
 * This software is released under the MIT License.
 * http://opensource.org/licenses/mit-license.php
 */
#include <cstdio>
#include <cstdint>
using namespace std;

uint16_t a, b;

void solve() {

    uint16_t num = 0;
    uint16_t taps = 0;
    while (taps < b-1) {
        taps += a-1;
        num++;
    }

    printf("%d\n", num);

}

int main() {

    scanf("%hd", &a);
    scanf("%hd", &b);

    solve();

}