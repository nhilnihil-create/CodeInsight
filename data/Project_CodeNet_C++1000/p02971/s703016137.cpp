/* 
 * Project: AtCoder Beginners Contest 134 C - Exception Handling
 * Author: toms74209200 <https://github.com/toms74209200>
 *
 * Created on 2020/09/16
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

uint64_t n;
vector<uint64_t> a;

void solve() {

    vector<uint64_t> sorted_a(n);
    copy(a.begin(), a.end(), sorted_a.begin());
    sort(sorted_a.begin(), sorted_a.end());
    for (auto i : a) {
        if (i == sorted_a[n-1]) {
            printf("%lld\n", sorted_a[n-2]);
        } else {
            printf("%lld\n", sorted_a[n-1]);
        }
    }
}

int main() {

    scanf("%lld", &n);
    a.resize(n);
    for (int i=0;i<n;i++) {
        scanf("%lld", &a[i]);
    }

    solve();
}