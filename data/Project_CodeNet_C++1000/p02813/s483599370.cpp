/* 
 * Project: AtCoder Beginners Contest 150 C - Count Order
 * Author: toms74209200 <https://github.com/toms74209200>
 *
 * Created on 2020/07/20
 * Copyright (c) 2020 toms74209200
 * 
 * This software is released under the MIT License.
 * http://opensource.org/licenses/mit-license.php
 */
#include <cstdio>
#include <algorithm>
#include <numeric>
#include <vector>
#include <map>
using namespace std;

int n;
vector<int> p;
vector<int> q;

void solve() {

    vector<int> first_list;
    for (int i=1;i<=n;i++) {
        first_list.push_back(i);
    }
    map<vector<int>, int> sort_list;
    do {
        sort_list[first_list] = sort_list.size();
    } while (next_permutation(first_list.begin(), first_list.end()));

    int cnt = abs(sort_list[p] - sort_list[q]);
    printf("%d\n", cnt);
    
}

int main() {

    scanf("%d", &n);
    for (int i=0;i<n;i++) {
        int tmp;
        scanf("%d", &tmp);
        p.push_back(tmp);
    }
    for (int i=0;i<n;i++) {
        int tmp;
        scanf("%d", &tmp);
        q.push_back(tmp);
    }

    solve();

}
