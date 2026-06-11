#include <bits/stdc++.h>
#define rep(i,n)for(int i=0;i<(n);i++)
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
typedef tuple<ll,ll,ll> T;
const long long INF = 1LL<<60;
const int MOD = 1000000000+7;
#define rev(s) (string((s).rbegin(), (s).rend()))
template < typename T > inline string toString( const T &a ) { ostringstream oss; oss << a; return oss.str(); };
// cout << fixed << setprecision(10) << ans << endl;
// *min_element(c + l, c + r) *max_element(c + l, c + r)
// int dx[8]={1,1,0,-1,-1,-1,0,1};
// int dy[8]={0,1,1,1,0,-1,-1,-1};
// int dx[4]={1,0,-1,0};
// int dy[4]={0,1,0,-1};
// struct Edge {
//   int to, id;
//   Edge(int to, int id): to(to), id(id) {}
// };

int main() {
    string L;cin>>L;
    int N = L.size();
    vector<vector<ll>> dp(N+1,vector<ll>(2,0));
    dp[0][1] = 1;
    rep(i,N) {
        //1 to 1
        if(L[i]=='1') {
            dp[i+1][1] = 2 * dp[i][1] % MOD;
        } else {
            dp[i+1][1] = dp[i][1];
        } 

        // 1 to 0
        if(L[i]=='1') {
            dp[i+1][0] = (dp[i+1][0] + dp[i][1]) % MOD;
        }

        // 0 to 0
        dp[i+1][0] = (dp[i+1][0] + 3 * dp[i][0]) % MOD;
    }
    cout<<(dp[N][0] + dp[N][1])%MOD<<endl; 
}