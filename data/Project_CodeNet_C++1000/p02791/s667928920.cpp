/* 
 * Project: AtCoder Beginners Contest 152 C - Low Elements
 * Author: toms74209200 <https://github.com/toms74209200>
 *
 * Created on 2020/07/18
 * Copyright (c) 2020 toms74209200
 * 
 * This software is released under the MIT License.
 * http://opensource.org/licenses/mit-license.php
 */
#include <cstdio>
#include <climits>
using namespace std;

int n;
int p[200000];

int main() {

    scanf("%d", &n);
    int min_p = INT_MAX;
    int cnt = 0;
    for (int i=0;i<n;i++) {
        scanf("%d", &p[i]);
        if (p[i] < min_p) {
            min_p = p[i];
            cnt++;
        }
    }
    printf("%d\n", cnt);

}