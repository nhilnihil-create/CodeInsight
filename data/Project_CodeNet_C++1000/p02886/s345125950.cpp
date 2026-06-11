/* 
 * Project: AtCoder Beginners Contest 143 B - TAKOYAKI FESTIVAL 2019
 * Author: toms74209200 <https://github.com/toms74209200>
 *
 * Created on 2020/08/15
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
vector<int32_t> d;

void solve() {

    int32_t sum = 0;
    for (int i=0;i<n;i++) {
        for (int j=i+1;j<n;j++) {
            sum += d[i]*d[j];
        }
    }
    printf("%d\n", sum);

}

int main() {

    scanf("%d", &n);
    for (int i=0;i<n;i++) {
        int32_t tmp;
        scanf("%d", &tmp);
        d.push_back(tmp);
    }

    solve();

}