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
#define INF INT32_MAX / 2
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

template <class T>
vector<T> divisor(T n) {
    vector<T> r;
    for (int i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            r.push_back(i);
            if (i * i != n)
                r.push_back(n / i);
        }
    }
    sort(r.begin(), r.end());
    return r;
}

signed main() {
    int n;
    cin >> n;
    vector<int> a(n + 1, 0);
    rep(i, n) cin >> a[i + 1];
    vector<int> sum(n + 1, 0);
    set<int> s;
    for (int i = n; i; i--) {
        if (a[i] == sum[i] % 2)
            continue;
        else {
            s.insert(i);
            auto v = divisor(i);
            for (auto j : v)
                sum[j]++;
        }
    }
    cout << s.size() << endl;
    for (auto i = s.begin(); i != s.end(); i++)
        cout << *i << endl;
    return 0;
}