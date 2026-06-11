/* 
 * Project: AtCoder Beginners Contest 156 B - Digits
 * Author: toms74209200 <https://github.com/toms74209200>
 *
 * Created on 2020/06/20
 * Copyright (c) 2020 toms74209200
 * 
 * This software is released under the MIT License.
 * http://opensource.org/licenses/mit-license.php
 */
#include <cstdio>
#include <vector>
using namespace std;

int n;
int k;

void solve() {

    vector<char> t;
    int q;
    // int rem;
    int cnt = 0;
    while (n) {
        q = n / k;
        // rem = n % k;
        // t.push_back((char)(rem + '0'));
        n = q;
        cnt++;
    }
    printf("%d\n", cnt);
    return;
}

int main() {

    scanf("%d", &n);
    scanf("%d", &k);

    solve();

}