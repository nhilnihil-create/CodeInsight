/* 
 * Project: AtCoder Beginners Contest 143 B - Roller Coaste
 * Author: toms74209200 <https://github.com/toms74209200>
 *
 * Created on 2020/08/17
 * Copyright (c) 2020 toms74209200
 * 
 * This software is released under the MIT License.
 * http://opensource.org/licenses/mit-license.php
 */
#include <cstdio>
#include <cstdint>
#include <cmath>
#include <vector>
using namespace std;

int32_t n;
int32_t k;
vector<int32_t> h;

void solve() {

    uint32_t cnt = 0;
    for (int32_t i : h) {
        if (i >= k) {
            cnt++;
        }
    }
    printf("%d\n", cnt);

}

int main() {

    scanf("%d", &n);
    scanf("%d", &k);
    for (int i=0;i<n;i++) {
        int32_t tmp;
        scanf("%d", &tmp);
        h.push_back(tmp);
    }

    solve();

}