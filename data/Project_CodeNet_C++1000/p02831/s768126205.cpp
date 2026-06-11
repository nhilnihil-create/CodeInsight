/* 
 * Project: AtCoder Beginners Contest 148 C - Snack
 * Author: toms74209200 <https://github.com/toms74209200>
 *
 * Created on 2020/08/01
 * Copyright (c) 2020 toms74209200
 * 
 * This software is released under the MIT License.
 * http://opensource.org/licenses/mit-license.php
 */
#include <cstdio>
#include <numeric>
using namespace std;

long a, b;

void solve() {

    long long number = lcm(a, b);
    printf("%lld\n", number);
}

int main() {

    scanf("%ld", &a);
    scanf("%ld", &b);

    solve();

}
