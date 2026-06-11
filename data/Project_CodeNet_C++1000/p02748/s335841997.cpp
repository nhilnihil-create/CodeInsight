#include <algorithm>
#include <cmath>
#include <functional>
#include <iostream>
#include <iterator>
#include <map>
#include <queue>
#include <unordered_map>
#include <vector>

using namespace std;

#define ll long long
#define el '\n'
#define rep(i, a, b) for (int i = a; i < b; i++)
#define repi(i, a, b) for (int i = a; i >= b; i--)
#define vi vector<int>
#define vii vector<pair<int, int>>
#define pii pair<int, int>
#define mp make_pair
#ifdef LOCAL
#define debug(fmt, ...) printf(fmt, ##__VA_ARGS__)
#define check(...) assert(__VA_ARGS__)
#else
#define debug(fmt, ...)
#define check(...)
#endif

#define INF 1000000

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int A, B, M;
    cin >> A >> B >> M;
    int a[A], b[B], x[M], y[M], c[M];
    int min_a = INF;
    rep(i, 0, A) {
        cin >> a[i];
        min_a = min(min_a, a[i]);
    }
    int min_b = INF;
    rep(i, 0, B) {
        cin >> b[i];
        min_b = min(min_b, b[i]);
    }
    int ans = min_a + min_b;
    // debug("here");
    rep(i, 0, M) {
        cin >> x[i] >> y[i] >> c[i];
        x[i]--;
        y[i]--;
        int this_one = a[x[i]] + b[y[i]] - c[i];
        ans = min(ans, this_one);
    }
    cout << ans;
}
