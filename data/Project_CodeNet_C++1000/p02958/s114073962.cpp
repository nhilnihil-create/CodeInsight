/* 
 * Project: AtCoder Beginners Contest 135 B - 0 or 1 Swap
 * Author: toms74209200 <https://github.com/toms74209200>
 *
 * Created on 2020/09/10
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

int32_t n;
vector<int32_t> p;

void solve() {

    vector<int32_t> sorted_p(n);
    copy(p.begin(), p.end(), sorted_p.begin());
    sort(sorted_p.begin(), sorted_p.end());
    uint32_t cnt = 0;
    for (int i=0;i<n;i++) {
        if (p[i] != sorted_p[i])
            cnt++;
    }
    if (cnt <= 2) {
        printf("YES\n");
    } else {
        printf("NO\n");
    }

}

int main() {

    scanf("%d", &n);
    p.resize(n);
    for (int i=0;i<n;i++) {
        scanf("%d", &p[i]);
    }

    solve();

}
