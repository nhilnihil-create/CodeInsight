/* 
 * Project: AtCoder Beginners Contest 140 C - Maximal Value
 * Author: toms74209200 <https://github.com/toms74209200>
 *
 * Created on 2020/09/06
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
vector<uint32_t> b;

void solve() {

    uint64_t sum = 0;
    sum += *b.begin();
    sum += *(b.end()-1);
    for (int i=0;i<n-2;i++) {
        sum += min(b[i], b[i+1]);
    }

    printf("%llu\n", sum);

}

int main() {

    scanf("%d", &n);
    b.resize(n-1);
    for (int i=0;i<n-1;i++) {
        scanf("%d", &b[i]);
    }

    solve();

}