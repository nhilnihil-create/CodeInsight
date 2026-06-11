/* 
 * Project: AtCoder Beginners Contest 175 B - Making Triangle
 * Author: toms74209200 <https://github.com/toms74209200>
 *
 * Created on 2020/08/29
 * Copyright (c) 2020 toms74209200
 * 
 * This software is released under the MIT License.
 * http://opensource.org/licenses/mit-license.php
 */
#include <cstdio>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

uint32_t n;
vector<uint32_t> l;

void solve() {

    sort(l.begin(), l.end());
    uint32_t cnt = 0;
    for (int i=0;i<n;i++) {
        for (int j=0;j<i;j++) {
            for (int k=0;k<j;k++) {
                if (l[i] != l[j] && l[j] != l[k]) {
                    if (l[k]+l[j] > l[i])
                        cnt++;
                }
            }
        }
    }
    printf("%d\n",cnt);
}

int main() {

    scanf("%d", &n);
    l.resize(n);
    for (int i=0;i<n;i++) {
        scanf("%d", &l[i]);
    }

    solve();

}