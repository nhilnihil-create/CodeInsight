/* 
 * Project: AtCoder Beginners Contest 149 B - Greedy Takahashi
 * Author: toms74209200 <https://github.com/toms74209200>
 *
 * Created on 2020/07/24
 * Copyright (c) 2020 toms74209200
 * 
 * This software is released under the MIT License.
 * http://opensource.org/licenses/mit-license.php
 */
#include <cstdio>
#include <algorithm>
#include <numeric>
using namespace std;

long a, b;
long k;

void solve() {

    long rest_a;
    long rest_b = b;
    if (k <= a) {
        rest_a = a - k;
    } else if (k <= a + b) {
        rest_a = 0;
        rest_b = b - k + a;
    } else {
        rest_a = 0;
        rest_b = 0;
    }
    printf("%ld %ld\n", rest_a, rest_b);
    return;
}

int main() {

    scanf("%ld", &a);
    scanf("%ld", &b);
    scanf("%ld", &k);

    solve();

}