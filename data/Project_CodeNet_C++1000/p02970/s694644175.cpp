/* 
 * Project: AtCoder Beginners Contest 134 B - Golden Apple
 * Author: toms74209200 <https://github.com/toms74209200>
 *
 * Created on 2020/09/15
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
int32_t d;

void solve() {

    int32_t cnt = (n+2*d)/(2*d+1);
    printf("%d\n", cnt);

}

int main() {

    scanf("%d", &n);
    scanf("%d", &d);

    solve();

}
