#include <cstdio>
#include <cmath>
#include <cstring>
#include <iostream>
#include <sstream>

#include <memory>
#include <string>
#include <vector>
#include <queue>
#include <list>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <stack>
#include <deque>
#include <algorithm>
#include <random>
#include <iomanip>
using namespace std;



int main(int argc, char *argv[]) {
    int n, k;
    vector<long long int> v;
    cin >> n >> k;
    int zeros = 0;
    for (int i = 0; i < n; i++) {
        long long int t;
        cin >> t;
        if (t == 0) zeros++;
        v.push_back(t);
    }
    v.push_back(0);
    if (k + zeros >= v.size()) {
        cout << 0 << endl;
        return 0;
    }
    unordered_map<int, unordered_map<int, long long int>> um1, um2;
    // [times][index]
    um1[0][0] = v[0];
    for (int i = 1; i < n; i++) {
        if (v[i] != v[0])
            um1[1][i] = v[i];
        else
            um1[0][i] = v[i];
    }
    um1[1][n] = 0;
    for (int i = 1; i < n; i++) {
        um2.clear();
        for (auto p1 : um1) {
            for (auto p2 : p1.second) {
                int times = p1.first;
                int index = p2.first;
                long long int c = p2.second;
                
                // change with last height
                if (times < k) {
                    if (um2[times + 1].find(index) == um2[times + 1].end())
                        um2[times + 1][index] = p2.second;
                    else
                        um2[times + 1][index] = min(p2.second, um2[times + 1][index]);
                }
                // not change
                if (um2[times].find(i) == um2[times].end())
                    um2[times][i] = max((long long int)0, v[i] - v[index]) + p2.second;
                else
                    um2[times][i] = min(um2[times][i], max((long long int)0, v[i] - v[index]) + p2.second);

                if (v[i] > 0 && times < k && 0) {
                    if (um2[times + 1].find(n) == um2[times + 1].end())
                        um2[times + 1][n] = p2.second;
                    else
                        um2[times + 1][n] = min(um2[times + 1][n], p2.second);
                }
            }
        }
        um1 = um2;

    }
    long long int res = -1;
    for (auto p1 : um1) {
        if (p1.first > k)
             continue;
        for (auto p2 : p1.second) {

            if (res == -1 || res > p2.second)
                res = p2.second;
        }
    }
    cout << res << endl;
}
