/* 
 * Project: AtCoder Beginners Contest 142 A - Odds of Oddness
 * Author: toms74209200 <https://github.com/toms74209200>
 *
 * Created on 2020/08/16
 * Copyright (c) 2020 toms74209200
 * 
 * This software is released under the MIT License.
 * http://opensource.org/licenses/mit-license.php
 */
#include <cstdio>
#include <cstdint>
using namespace std;

uint32_t n;

void solve() {

    if (!(n&1)) {
        printf("%f\n", 0.5);
    } else if (n == 1) {
        printf("%f\n", 1.0);
    } else {
        printf("%f\n", (n/2+1)/(float)n);
    }


}

int main() {

    scanf("%d", &n);

    solve();

}