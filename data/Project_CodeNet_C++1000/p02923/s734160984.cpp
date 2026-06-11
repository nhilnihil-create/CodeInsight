/* 
 * Project: AtCoder Beginners Contest 139 C - Lower
 * Author: toms74209200 <https://github.com/toms74209200>
 *
 * Created on 2020/08/26
 * Copyright (c) 2020 toms74209200
 * 
 * This software is released under the MIT License.
 * http://opensource.org/licenses/mit-license.php
 */
#include <cstdio>
#include <cstdint>
#include <vector>
using namespace std;

uint32_t n;
vector<uint64_t> h;

void solve() {


    uint32_t max_cnt = 0;
    for (auto i=h.begin();i<h.end();i++) {
        uint32_t cnt = 0;
        auto iter = i;
        while (*iter >= *next(iter) && iter < h.end()-1) {
            cnt++;
            iter++;
        }
        max_cnt = max(max_cnt, cnt);
        if (iter == h.end()-1) {
            break;
        }
    }

    printf("%d\n", max_cnt);
}

int main() {

    scanf("%d", &n);
    h.resize(n);
    for (int i=0;i<n;i++) {
        scanf("%lld", &h[i]);
    }

    solve();
}