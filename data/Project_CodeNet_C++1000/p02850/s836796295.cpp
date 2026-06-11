#include <algorithm>
#include <bitset>
#include <cmath>
#include <deque>
#include <functional>
#include <iomanip>
#include <iostream>
#include <limits>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <utility>
#include <vector>
using ll = long long;
#define rep(i, n) for (int i = 0; i < n; i++)
#define repk(i, k, n) for (int i = k; i < n; i++)
#define MOD 1000000007
#define INF 1e9
#define PIE 3.14159265358979323

template <class T>
inline bool chmin(T &a, T b) {
    if (a > b) {
        a = b;
        return true;
    }
    return false;
}
template <class T>
inline bool chmax(T &a, T b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
}
template <class T>
T GCD(T a, T b) {
    if (b == 0)
        return a;
    else
        return GCD(b, a % b);
}
template <class T>
inline T LCM(T a, T b) {
    return (a * b) / GCD(a, b);
}

using namespace std;
//#inculude <bits/stdc++.h>
//#define int long long

signed main() {
    int n;
    cin >> n;
    int a, b;
    vector<set<int>> v(n);
    vector<pair<int, int>> res(n - 1);
    rep(i, n - 1) {
        cin >> a >> b;
        v[a - 1].insert(b - 1);
        v[b - 1].insert(a - 1);
        res.push_back(make_pair(a - 1, b - 1));
    }
    map<pair<int, int>, int> re;
    int m = 0;
    rep(i, n) chmax(m, (int)v[i].size());
    cout << m << endl;
    vector<set<int>> used(n);
    queue<int> q;
    q.push(0);
    while (!q.empty()) {
        int x = q.front();
        q.pop();
        int index = 1;
        for (auto itr = v[x].begin(); itr != v[x].end(); itr++) {
            while (true) {
                if (used[x].find(index) == used[x].end()) {
                    used[x].insert(index);
                    used[*itr].insert(index);
                    v[*itr].erase(x);
                    auto p = make_pair(x, *itr);
                    re[p] = index;
                    q.push(*itr);
                    if (index == m)
                        index = 1;
                    else
                        index++;
                    break;
                }
                if (index == m)
                    index = 1;
                else
                    index++;
            }
        }
    }
    for (auto i : res)
        if (re[i] != 0)
            cout << re[i] << endl;
    return 0;
}