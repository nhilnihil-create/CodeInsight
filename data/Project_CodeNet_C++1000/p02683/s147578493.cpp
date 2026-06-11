/* 
 * Project: AtCoder Beginners Contest 167 C - Skill Up
 * Author: toms74209200 <https://github.com/toms74209200>
 *
 * Created on 2020/08/04
 * Copyright (c) 2020 toms74209200
 * 
 * This software is released under the MIT License.
 * http://opensource.org/licenses/mit-license.php
 */
#include <algorithm>
#include <vector>
#include <cstdio>
#include <climits>
using namespace std;

int n, m, x;
int c_price[12];
int a[12][12];

void solve() {

    int bit_max = 1<<n;
    int sum_price = INT_MAX;

    for (int i=0;i<bit_max;i++) {
        vector<int> skill(m);
        int cost = 0;
        for (int j=0;j<n;j++) {
            if ((i>>j)&1) {
                cost += c_price[j];
                for (int k=0;k<m;k++) {
                    skill[k] += a[j][k];
                }
            }
        }
        bool achieve = true;
        for (int k=0;k<m;k++) {
            if (skill[k] < x)
                achieve = false;
        }
        if (achieve)
            sum_price = min(sum_price, cost);
    }
    if (sum_price == INT_MAX) {
        printf("%d\n", -1);
        return;
    } else {
        printf("%d\n", sum_price);
        return;
    }
}

int main() {

    scanf("%d", &n);
    scanf("%d", &m);
    scanf("%d", &x);
    for (int i=0;i<n;i++) {
        scanf("%d", &c_price[i]);
        for (int j=0;j<m;j++) {
            scanf("%d", &a[i][j]);
        }
    }

    solve();
}