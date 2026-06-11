#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <ctime>
#include <cassert>
#include <complex>
#include <string>
#include <cstring>
#include <chrono>
#include <random>
#include <queue>
#include <bitset>
#include <stack>
#include <functional>

#ifdef LOCAL
    #define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
    #define eprintf(...) 42
#endif

#define rep_(i, a_, b_, a, b, ...) for (int i = (a), i##_len = (b); i < i##_len; ++i)
#define rep(i, ...) rep_(i, __VA_ARGS__, __VA_ARGS__, 0, __VA_ARGS__)
#define reprev_(i, a_, b_, a, b, ...) for (int i = (b-1), i##_min = (a); i >= i##_min; --i)
#define reprev(i, ...) reprev_(i, __VA_ARGS__, __VA_ARGS__, 0, __VA_ARGS__)
#define all(x) (x).begin(), (x).end()
template <class T> bool chmax(T &a, const T &b) { if (a < b) { a = b; return 1; } return 0; }
template <class T> bool chmin(T &a, const T &b) { if (b < a) { a = b; return 1; } return 0; }
template <class T> T gcd(T a, T b) { return b ? gcd(b, a % b) : a; }
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair <int,int> P;
typedef long double ld;

int main(void)
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n, m; cin >> n >> m;
    vector<vector<int> > graph(3 * n);
    rep (i, m) {
        int a, b; cin >> a >> b; a--; b--;
        rep (j, 3) graph[3 * a + j].push_back(3 * b + (j + 1) % 3);
    }
    vector<bool> used(3 * n);
    int s, t; cin >> s >> t; s--; t--;
    used[3 * s] = true;
    priority_queue<P> que; que.emplace(0, 3 * s);
    while (!que.empty()) {
        P p = que.top(); que.pop();
        if (p.second == 3 * t) {
            cout << -p.first / 3 << "\n";
            return 0;
        }
        for (auto i : graph[p.second]) {
            if (!used[i]) {
                que.emplace(p.first - 1, i);
                used[i] = true;
            }
        }
    }
    cout << -1 << "\n";
    return 0;
}