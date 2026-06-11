/* 
 * Project: AtCoder Beginners Contest 155 A - Poor
 * Author: toms74209200 <https://github.com/toms74209200>
 *
 * Created on 2020/06/23
 * Copyright (c) 2020 toms74209200
 * 
 * This software is released under the MIT License.
 * http://opensource.org/licenses/mit-license.php
 */
#include <cstdio>
using namespace std;

int a, b, c;

void solve() {
    if (a == b & b == c) {
        printf("No\n");
        return;
    }
    if (!(a ^ b) | !(b ^ c) | !(c ^ a)) {
        printf("Yes\n");
        return;
    }
    printf("No\n");
    return;

}

int main() {

    scanf("%d", &a);
    scanf("%d", &b);
    scanf("%d", &c);

    solve();

}