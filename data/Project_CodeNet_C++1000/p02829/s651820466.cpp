/* 
 * Project: AtCoder Beginners Contest 148 A - Round One
 * Author: toms74209200 <https://github.com/toms74209200>
 *
 * Created on 2020/07/30
 * Copyright (c) 2020 toms74209200
 * 
 * This software is released under the MIT License.
 * http://opensource.org/licenses/mit-license.php
 */
#include <cstdio>
using namespace std;

int a, b;

void solve() {

    int answer = 6 - a - b;
    printf("%d\n", answer);
}

int main() {

    scanf("%d", &a);
    scanf("%d", &b);

    solve();

}