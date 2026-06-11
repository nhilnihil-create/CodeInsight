/* 
 * Project: AtCoder Beginners Contest 138 C - Alchemist
 * Author: toms74209200 <https://github.com/toms74209200>
 *
 * Created on 2020/09/05
 * Copyright (c) 2020 toms74209200
 * 
 * This software is released under the MIT License.
 * http://opensource.org/licenses/mit-license.php
 */
#include <cstdio>
#include <cstdint>
#include <vector>
#include <algorithm>
using namespace std;

uint32_t n;
vector<uint32_t> v;

void solve() {


    sort(v.begin(), v.end());
    double ave = (v[0]+v[1])/2.0;
    for (int i=2;i<n;i++) {
        ave = (ave + v[i])/2.0;
    }

    printf("%lf\n", ave);
}

int main() {

    scanf("%d", &n);
    v.resize(n);
    for (int i=0;i<n;i++) {
        scanf("%d", &v[i]);
    }

    solve();
}