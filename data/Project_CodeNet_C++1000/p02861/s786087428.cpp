/* 
 * Project: AtCoder Beginners Contest 145 C - Average Length
 * Author: toms74209200 <https://github.com/toms74209200>
 *
 * Created on 2020/08/11
 * Copyright (c) 2020 toms74209200
 * 
 * This software is released under the MIT License.
 * http://opensource.org/licenses/mit-license.php
 */
#include <cstdio>
#include <cmath>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

int n;
vector<pair<int,int>> p;
vector<int> x;
vector<int> y;

double get_distance(pair<int,int> p1, pair<int,int> p2) {
    int dx = p1.first - p2.first;
    int dy = p1.second - p2.second;
    return sqrt(dx*dx + dy*dy);
}

void solve() {

    vector<int> idx(n);
    for (int i=0;i<n;i++) {
        idx[i] = i;
    }

    vector<double> sums(n);
    int cnt = 0;
    do {
        double sum = 0;
        for (int i=0;i<n-1;i++) {
            sum += get_distance(p[idx[i]],p[idx[i+1]]);
        }
        sums.push_back(sum);
        cnt++;
    } while (next_permutation(idx.begin(), idx.end()));
    double average = accumulate(sums.begin(), sums.end(), 0.0) / cnt;
    printf("%lf\n", average);
}

int main() {

    scanf("%d", &n);
    for (int i=0;i<n;i++) {
        int tmp_x;
        int tmp_y;
        scanf("%d", &tmp_x);
        scanf("%d", &tmp_y);
        pair<int,int> tmp_p;
        tmp_p.first = tmp_x;
        tmp_p.second = tmp_y;
        p.push_back(tmp_p);
    }

    solve();
}