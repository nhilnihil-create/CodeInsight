/* 
 * Project: NOMURA Programing Contest A - Study Scheduling
 * Author: toms74209200 <https://github.com/toms74209200>
 *
 * Created on 2020/05/30
 * Copyright (c) 2020 toms74209200
 * 
 * This software is released under the MIT License.
 * http://opensource.org/licenses/mit-license.php
 */
#include <cstdio>
#include <cmath>
using namespace std;

int h1;
int h2;
int m1;
int m2;
int k;

void solve() {
    int wake_time = 0;
    wake_time = h2*60 + m2 - (h1 *60 + m1);

    printf("%d\n", wake_time - k);
}

int main() {

    scanf("%d", &h1);
    scanf("%d", &m1);
    scanf("%d", &h2);
    scanf("%d", &m2);
    scanf("%d", &k);

    solve();

}