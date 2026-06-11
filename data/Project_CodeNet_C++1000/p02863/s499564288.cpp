#include <bits/stdc++.h>
#define rep(i,cc,n) for(int i=cc;i<=n;++i)
#define drep(i,cc,n) for(int i=cc;i>=n;--i)
#define sz(s) (int)(s.size())
#define vecprint(v) rep(i,0,v.size()-1)cout << v[i] << " ";cout << endl;
#define arrprint(v,n) rep(i,0,n-1)cout << v[i] << " ";cout << endl;
#define matprint(v,n,m) rep(i,0,n-1){rep(j,0,m-1){cout << v[i][j] << " ";}cout << endl;}
#define SORT(v) sort(v.begin(), v.end())
#define REV(v) reverse(v.begin(), v.end())
using namespace std;
const int mod=1000000007;
const int INF=1001001001;
typedef long long ll;
typedef pair<int,int> P;
template<typename T>
using priority_queue_rev = priority_queue<T, vector<T>, greater<T>>; //小さいものから取り出す

int main(){
    int n,t;
    cin >> n >> t;
    vector<P> ab(n);
    rep(i,0,n-1)cin >> ab[i].first >> ab[i].second;
    SORT(ab);
    // REV(ab);
    int dp[n][t];
    int ans = 0;
    rep(i,0,t-1){
        if(i-ab[0].first >= 0)dp[0][i] = ab[0].second;
        else dp[0][i] = 0;
    }
    ans = ab[0].second;
    rep(i,1,n-1){
        rep(j,0,t-1){
            if(j-ab[i].first >= 0)dp[i][j] = max(dp[i-1][j], dp[i-1][j-ab[i].first] + ab[i].second);
            else dp[i][j] = dp[i-1][j];
        }
        ans = max(ans, dp[i-1][t-1] + ab[i].second);
    }
    // matprint(dp,n-1,t);
    // int ans = dp[n-2][t-1] + ab[n-1].first;

    cout << ans << endl;
//  printf("%.10f\n",ans);

    return 0;
}