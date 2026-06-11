/* 
 * Project: AtCoder Beginners Contest 140 B - Buffet
 * Author: toms74209200 <https://github.com/toms74209200>
 *
 * Created on 2020/08/23
 * Copyright (c) 2020 toms74209200
 * 
 * This software is released under the MIT License.
 * http://opensource.org/licenses/mit-license.php
 */
#include <cstdio>
#include <cstdint>
#include <vector>
using namespace std;

uint16_t n;
vector<uint32_t> a, b, c;

void solve() {

    uint32_t sum = 0;
    uint32_t last = 21;
    for (int i=0;i<n;i++) {
        sum += b[a[i]-1];
        if (a[i] - last == 1) {
            sum += c[last-1];
        }
        last = a[i];
    }
    printf("%d\n",sum);

}

int main() {

    scanf("%hd", &n);
    uint32_t tmp = 0;
    for (int i=0;i<n;i++) {
        scanf("%d", &tmp);
        a.push_back(tmp);
    }
    for (int i=0;i<n;i++) {
        scanf("%d", &tmp);
        b.push_back(tmp);
    }
    for (int i=0;i<n-1;i++) {
        scanf("%d", &tmp);
        c.push_back(tmp);
    }

    solve();

}