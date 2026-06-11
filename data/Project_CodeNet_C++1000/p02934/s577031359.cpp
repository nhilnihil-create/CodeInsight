/* 
 * Project: AtCoder Beginners Contest 139 B - Resistors in Parallel
 * Author: toms74209200 <https://github.com/toms74209200>
 *
 * Created on 2020/08/28
 * Copyright (c) 2020 toms74209200
 * 
 * This software is released under the MIT License.
 * http://opensource.org/licenses/mit-license.php
 */
#include <cstdio>
#include <cstdint>
#include <vector>
#include <numeric>
#include <functional>
using namespace std;

uint16_t n;
vector<uint32_t> a;

void solve() {

    double sum = 0;

    for (auto i : a) {
        sum += 1 / (double)i;
    }

    double inv_sum = 1 / sum;

    printf("%lf\n", inv_sum);

}

int main() {

    scanf("%hd", &n);
    a.resize(n);
    for (int i=0;i<n;i++) {
        scanf("%d", &a[i]);
    }

    solve();

}