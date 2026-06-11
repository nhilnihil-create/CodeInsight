/* 
 * Project: AtCoder Beginners Contest 144 B - 81
 * Author: toms74209200 <https://github.com/toms74209200>
 *
 * Created on 2020/08/08
 * Copyright (c) 2020 toms74209200
 * 
 * This software is released under the MIT License.
 * http://opensource.org/licenses/mit-license.php
 */
#include <cstdio>
#include <cstdint>
#include <cmath>
using namespace std;

int32_t n;

void solve() {

    int max_term = sqrt(n);
    for (int32_t i=1;i<max_term+1;i++) {
        if (n%i==0 && n/i<10) {
            printf("Yes\n");
            return;
        }
    }
    printf("No\n");

}

int main() {

    scanf("%d", &n);

    solve();

}