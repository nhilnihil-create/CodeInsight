/* 
 * Project: AtCoder Beginners Contest 136 C - Build Stairs
 * Author: toms74209200 <https://github.com/toms74209200>
 *
 * Created on 2020/09/09
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
vector<int64_t> h;

void solve() {

    bool is_ok = true;
    for (int i=n-2;i>=0;i--) {
        if (h[i] > h[i+1]) {
            if (h[i] - h[i+1] >= 2) {
                is_ok = false;
                break;
            }
            h[i]--;
        }
    }
    if (is_ok)
        printf("Yes\n");
    else
        printf("No\n");

}

int main() {

    scanf("%d", &n);
    h.resize(n);
    for (int i=0;i<n;i++) {
        scanf("%lld", &h[i]);
    }

    solve();
}