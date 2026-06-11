#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i = 0; i < (ll)(n); ++i)
#define erep(i, n) for (ll i = 0; i <= (ll)(n); ++i)
#define FOR(i,a,b) for (ll i = (a); i < (ll)(b); ++i)
#define EFOR(i,a,b) for (ll i = (a); i <= (ll)(b); ++i)
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } }

typedef pair<ll, ll> P;

ll modnum = 1000000000+7;

long long modpow(long long a, long long n, long long mod) {
    long long res = 1;
    while (n > 0) {
        if (n & 1) res = res * a % mod;
        a = a * a % mod;
        n >>= 1;
    }
    return res;
}

// dp[i][0] = i番目まで見たときに、Lのi番目とa+bのi番目が一致するときの最大値
// dp[i][1] = i番目まで見たときに、未満が確定

ll dp[100005][2];

int main() {
    string l; cin >> l;
    ll ans = 0;
    dp[0][0] = 1;
    rep(i, l.size()) {
        // aとbの和が1or0で考える
        // i桁目のa+b = 0
        if(l[i] == '0') {
            // かつl[i]が0の場合
            dp[i+1][0] = dp[i][0];
            dp[i+1][1] = dp[i][1];
        } else {
            // かつl[i]が1の場合
            // i番目のa+b=0ということは、次の状態は必ずL未満と言えるので
            dp[i+1][1] = (dp[i][0] + dp[i][1]) % modnum;
        }

        // i桁目のa+b = 1
        if(l[i] == '0') {
            // かつl[i]が0の場合

            // a+b = 1 , l[i] = 0　なので、dp[i+1][0]への遷移はありえない
            // 未満だけ遷移していく, {a=1,b=0}, {a=0,b=1}の2パターンなので、2をかける
            dp[i+1][1] += dp[i][1]*2;
            dp[i+1][1] %= modnum;
        } else {
            // かつl[i]が1の場合
            dp[i+1][0] += dp[i][0] * 2;
            dp[i+1][0] %= modnum;
            dp[i+1][1] += dp[i][1] * 2;
            dp[i+1][1] %= modnum;
        }
    }

    cout << (dp[l.size()][0]+dp[l.size()][1]) % modnum << endl;
    return 0;

}

// 161999316
// 162261460
//    524288