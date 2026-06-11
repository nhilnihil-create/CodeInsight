#include <algorithm>
#include <bitset>
#include <cassert>
#include <cmath>
#include <deque>
#include <functional>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <tuple>
#include <vector>

using namespace std;
typedef long long ll;

#define rep(i, n) for (ll i = 0; i < (n); i++)
#define reps(i, f, n) for (ll i = (f); i < (n); i++)
#define repr(i, n) for (ll i = n; i >= 0; i--)
#define repv(v) for (auto it = (v).begin(); it != (v).end(); it++)
#define ALL(x) (x).begin(), (x).end()
#define SZ(x) ((int)(x).size())
#define pb push_back
#define INIT    \
    cin.tie(0); \
    ios::sync_with_stdio(false);

template <class T>
inline bool chmax(T& a, T b) {
    return a = (a < b) ? b : a;
}
template <class T>
inline bool chmin(T& a, T b) {
    return a = (a > b) ? b : a;
}

ll const INF = 1LL << 60;
ll const MOD = 1000000007;
ll const MAX_N = 3234566670;
// ll const MAX_N = 1000;
vector<ll> nums;

void dfs(ll n) {
    if (n > MAX_N) return;

    nums.pb(n);
    ll r = n % 10;

    for (ll i = -1; i <= 1; i++) {
        if (r + i >= 0 && r + i <= 9) {
            dfs(n * 10 + r + i);
        }
    }
}

int main() {
    INIT;
    ll K;
    cin >> K;

    reps(i, 1, 10) { dfs(i); }
    sort(ALL(nums));
    // repv(nums) cout << *it << " ";
    // cout << endl;

    cout << nums[K - 1] << endl;

    return 0;
}