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
#include <random>
#include <complex>
#include <functional>

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

    ll N;
    cin >> N;
    vec A(N), B(N);
    Rep (i, N) {
        cin >> A[i];
    }

    iota(B.begin(), B.end(), 0);

    sort(B.begin(), B.end(), [&](ll a, ll b) {return A[a] >= A[b];});

    mat dp(N+1, vec(N+1, 0));

    Rep (i, N) {
        Rep (j, i+1) {
            chmax(dp[i+1][j+1], dp[i][j]+A[B[i]]*abs(j-B[i]));
            chmax(dp[i+1][j], dp[i][j]+A[B[i]]*abs(N-1-i+j-B[i]));
        }
    }

    // Rep (i, N+1) {
    //     Rep (j, N+1) {
    //         cout << dp[i][j] << " \n"[j==N];
    //     }
    // }

    ll ans = 0;
    Rep (i, N+1) {
        chmax(ans, dp[N][i]);
    }

    cout << ans << endl;
}