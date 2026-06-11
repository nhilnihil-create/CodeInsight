/* 
 * Project: AtCoder Beginners Contest 136 B - Uneven Numbers
 * Author: toms74209200 <https://github.com/toms74209200>
 *
 * Created on 2020/09/08
 * Copyright (c) 2020 toms74209200
 * 
 * This software is released under the MIT License.
 * http://opensource.org/licenses/mit-license.php
 */
#include <cstdio>
#include <cstdint>
#include <string>
using namespace std;

int32_t n;

void solve() {

    uint32_t odd = 0;

    for (int i=1;i<=n;i++) {
        if (to_string(i).length()%2==1) {
            odd++;
        }
    }

    printf("%d\n", odd);

}

int main() {

    scanf("%d", &n);

    solve();

}
