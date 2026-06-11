/* 
 * Project: M-SOLUTIONS プロコンオープン 2020 D - Road to Millionaire
 * Author: toms74209200 <https://github.com/toms74209200>
 *
 * Created on 2020/07/28
 * Copyright (c) 2020 toms74209200
 * 
 * This software is released under the MIT License.
 * http://opensource.org/licenses/mit-license.php
 */
#include <cstdio>
using namespace std;

int n;
int a[80];

void solve() {
    long money = 1000;
    for (int i=0;i<n-1;i++) {
        if (a[i] < a[i+1]) {
            money += (a[i+1]-a[i]) * (long)(money/a[i]);
        }
    }
    printf("%ld\n", money);
}

int main() {

    scanf("%d", &n);
    for (int i=0;i<n;i++) {
        scanf("%d", &a[i]);
    }

    solve();
}