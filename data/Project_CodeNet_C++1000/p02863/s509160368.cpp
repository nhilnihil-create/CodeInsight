#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < n; i++)
#define rep2(i, x, n) for(int i = x; i <= n; i++)
#define rep3(i, x, n) for(int i = x; i >= n; i--)
#define elif else if
#define sp(x) fixed << setprecision(x)
#define pb(x) push_back(x)
#define all(x) x.begin(), x.end()
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pil = pair<int, ll>;
using pli = pair<ll, int>;
using pll = pair<ll, ll>;
const ll MOD = 1e9+7;
//const ll MOD = 998244353;
const int inf = 1e9;
const ll INF = 1e18;
const ld EPS = 1e-10;

int main(){
    int N, T;
    cin >> N >> T;
    pii p[N];
    rep(i, N){
        int A, B; cin >> A >> B;
        p[i] = pii(B, -A);
    }
    sort(p, p+N);
    //dp[i][j]:=[0,i)の皿でT以内に獲得できる美味しさの合計
    int dp[N+1][T];
    fill(dp[0], dp[N+1], 0);
    rep(i, N){
        int c = p[i].first, t = -p[i].second;
        rep(j, T){
            dp[i+1][j] = max(dp[i+1][j], dp[i][j]);
            if(j+t >= T) continue;
            dp[i+1][j+t] = max(dp[i+1][j+t], dp[i][j]+c);
        }
    }
    int sumt = 0, sumv = 0, ans = 0;
    //最後にi番目の料理を使う
    rep3(i, N-1, 0){
        if(sumt >= T) break;
        sumv += p[i].first;
        ans = max(ans, dp[i][T-1-sumt]+sumv);
        sumt -= p[i].second;
    }
    cout << ans << endl;
}