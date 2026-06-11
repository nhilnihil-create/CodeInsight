/* 
 * Project: AtCoder Beginners Contest 137 A - Transfer
 * Author: toms74209200 <https://github.com/toms74209200>
 *
 * Created on 2020/09/07
 * Copyright (c) 2020 toms74209200
 * 
 * This software is released under the MIT License.
 * http://opensource.org/licenses/mit-license.php
 */
#include <cstdio>
#include <cstdint>
using namespace std;

int32_t a, b, c;

void solve() {

    int32_t rest = 0;
    if (a-b > c) {
        ;
    } else {
        rest = c-(a-b);
    }

    printf("%d\n", rest);
}

int main() {

    scanf("%d", &a);
    scanf("%d", &b);
    scanf("%d", &c);

    solve();

}