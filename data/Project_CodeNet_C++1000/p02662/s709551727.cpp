#include <bits/stdc++.h>
#define ALL(A) (A).begin(), (A).end()
#define ll long long
#define rep(i, n) for (int i = 0; i < (n); i++)

using namespace std;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

int dx[] = { 0, 1, -1, 0, 1, -1, 1, -1 };  // i<4:4way i<8:8way
int dy[] = { 1, 0, 0, -1, 1, -1, -1, 1 };

const ll mod = 998244353;
const ll INF = -1 * ((1LL << 63) + 1);
const int inf = -1 * ((1 << 31) + 1);

ll dp[3003][3003]; // dp[i][j] := i番目まで見て合計値がjとなるような部分集合全てについて
// それを含む数の個数

int main(void){
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    ll n,s;
    cin >> n >> s;
    vector<int> a(n);
    rep(i,n)cin >> a[i];
    dp[0][0] = 1;
    for(int i=0;i<n;i++){
        for(int j=0;j<=s;j++){
            // a[i]を使わない場合はそれを含む集合に入れる入れないの
            // 2通りあるのでdp[i+1][j]
            dp[i+1][j] += dp[i][j] * 2 % mod;
            if(j-a[i]>=0)dp[i+1][j] += dp[i][j-a[i]];
            dp[i+1][j] %= mod;
        }
    }
    cout << dp[n][s] << endl;
}