#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <string>
#include <utility>
#include <algorithm>
#include <cstdio>
#include <iomanip>
#include <queue>
#include <deque>
#include <stack>
#include <fstream>
#include <cmath>

#define ll int64_t
#define Rep(i, n) for (ll i = 0; i < n; i++)
using namespace std;
typedef vector<ll> vec;
typedef vector<vec> mat;

const ll inf = 1LL << 60;

template<class T> inline void chmin(T& a, T b) {
    if (a > b) {
        a = b;
    }
}
template<class T> inline void chmax(T& a, T b) {
    if (a < b) {
        a = b;
    }
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    ofstream w_file("abc145_f.txt", ios::out);

    ll N, K;
    cin >> N >> K;
    vector<ll> H;
    H.push_back(0);
    Rep (i, N) {
        ll h;
        cin >> h;
        H.push_back(h);
    }

    mat dp(N+1, vec(N+1, inf));
    dp[0][0] = 0;

    Rep (i, N) {
        Rep (j, N) {
            for (ll k = j+1; k <= N; k++) {
                chmin(dp[i+1][k], dp[i][j] + max((ll)0, H[k]-H[j]));
            }
        }
    }

    Rep (i, N+1) {
        Rep (j, N+1) {
            w_file << dp[i][j] << " ";
        }
        w_file << "\n";
    }

    ll ans = inf;
    Rep (i, N+1) {
        chmin(ans, dp[N-K][i]);
    }

    cout << ans << "\n";
}