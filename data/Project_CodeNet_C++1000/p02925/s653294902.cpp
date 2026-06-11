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

vector<vector<int> > graph;
vector<bool> used;
vector<int> in, topology;

int f (int i, int j, int n) {
    int a = i, b = j;
    if (a > b) swap(a, b);
    return (a - 1) * (2 * n - a) / 2 + (b - a - 1);
}

int main(void)
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n; cin >> n;
    int comb = n * (n - 1) / 2;
    graph.resize(comb);
    in.resize(comb);
    used.resize(comb);
    rep (i, n) {
        vector<int> a(n - 1);
        rep (j, n - 1) cin >> a[j];
        rep (j, 1, n - 1) {
            graph[f(i + 1, a[j - 1], n)].push_back(f(i + 1, a[j], n));
            in[f(i + 1, a[j], n)]++;
        }
    }
    rep (i, comb) {
        for (int j : graph[i]) eprintf("(%d,%d)", i, j);
        eprintf("\n");
    }
    fflush(stderr);

    stack<int> st;
    rep (i, comb) if (in[i] == 0) st.push(i);
    while (!st.empty()) {
        int now = st.top(); st.pop();
        topology.push_back(now);
        for (int i : graph[now]) {
            in[i]--;
            if (in[i] == 0) st.push(i);
        }
    }
    if (topology.size() != comb) {
        cout << "-1\n";
    } else {
        rep (i, comb) eprintf("%d ", topology[i]); eprintf("\n");
        vector<int> dp(comb);
        int ans = 0;
        for (int i : topology) {
            for (int j : graph[i]) {
                chmax(dp[j], dp[i] + 1);
            }
            chmax(ans, dp[i]);
        }
        cout << ans + 1 << "\n";
    }
    return 0;
}