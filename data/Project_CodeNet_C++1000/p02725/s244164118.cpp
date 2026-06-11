/* 
 * Project: AtCoder Beginners Contest 160 C - Traveling Salesman around Lake
 * Author: toms74209200 <https://github.com/toms74209200>
 *
 * Created on 2020/07/15
 * Copyright (c) 2020 toms74209200
 * 
 * This software is released under the MIT License.
 * http://opensource.org/licenses/mit-license.php
 */
#include <cstdio>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

int k;
int n;
vector<int> a;

void solve() {
    vector<int> diff;
    diff.push_back(k+*a.begin()-a[n-1]);
    for (auto i=a.begin();i!=a.end();i++) {
        diff.push_back(*(i+1) - *i);
    }
    sort(diff.begin(), diff.end()-1);
    // for (auto i=diff.begin();i!=diff.end()-1;i++) {
    //     printf("%d\n", *i);
    // }
    int sum = accumulate(diff.begin(), diff.end()-2, 0);
    printf("%d\n", sum);
}

int main() {

    scanf("%d", &k);
    scanf("%d", &n);
    for (int i=0;i<n;i++) {
        int tmp;
        scanf("%d", &tmp);
        a.push_back(tmp);
    }

    solve();

}