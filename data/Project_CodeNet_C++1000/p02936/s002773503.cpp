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
    int n, q, a, b, x, y;
    cin >> n >> q;
    vector<vector<int>> tree(n, vector<int>(0));
    rep(i, n - 1) {
        cin >> a >> b;
        a--;
        b--;
        tree[a].push_back(b);
        tree[b].push_back(a);
    }
    vector<int> c(n, 0);
    rep(i, q) {
        cin >> x >> y;
        c[x - 1] += y;
    }
    vector<bool> is_visited(n, false);
    queue<int> qu;
    qu.push(0);
    is_visited[0] = true;
    while (!qu.empty()) {
        int top = qu.front();
        qu.pop();
        for (auto o : tree[top]) {
            if (is_visited[o] == false) {
                c[o] += c[top];
                is_visited[o] = true;
                qu.push(o);
            }
        }
    }
    rep(i, n) {
        if (i != n - 1)
            cout << c[i] << ' ';
        else
            cout << c.back() << endl;
    }
}