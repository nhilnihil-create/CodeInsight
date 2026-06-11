/* 
 * Project: AtCoder Beginners Contest 159 A - The Number of Even Pairs
 * Author: toms74209200 <https://github.com/toms74209200>
 *
 * Created on 2020/06/13
 * Copyright (c) 2020 toms74209200
 * 
 * This software is released under the MIT License.
 * http://opensource.org/licenses/mit-license.php
 */
#include <cstdio>
using namespace std;

int n, m;

void solve() {
   
   printf("%d\n", n*(n-1)/2+m*(m-1)/2);

}

int main() {

    scanf("%d", &n);
    scanf("%d", &m);

    solve();

}