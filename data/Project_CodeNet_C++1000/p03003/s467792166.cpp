#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define rrep(i,n) for(int i=(int)(n-1);i>=0;i--)
#define FOR(i,n,m) for(int i=n;i<=(int)(m);i++)
#define RFOR(i,n,m) for(int i=(int)(n);i>=m;i--)
#define all(x) (x).begin(),(x).end()
#define sz(x) int(x.size())
typedef long long ll;
const int INF = 1e9;
const int MOD = 1e9+7;
const ll LINF = 1e18;
const double PI=acos(-1);
using namespace std;
vector<int> dx={1,0,-1,0};
vector<int> dy={0,1,0,-1};
template<class T>
vector<T> make_vec(size_t a){
    return vector<T>(a);
}
template<class T, class... Ts>
auto make_vec(size_t a, Ts... ts){
    return vector<decltype(make_vec<T>(ts...))>(a, make_vec<T>(ts...));
}

int main() {
    int n,m;
    cin>>n>>m;
    vector<int> s(n),t(m);
    rep(i,n) cin>>s[i];
    rep(i,m) cin>>t[i];
    
    auto dp=make_vec<ll>(n+10,m+10);
    //dp[i][j] -> s[i],t[i]までみたときの共通部分列の個数
    dp[0][0]=1;
    rep(i,n+1) {
        rep(j,m+1) {
            if(i-1>=0) dp[i][j]+=dp[i-1][j];
            if(j-1>=0) dp[i][j]+=dp[i][j-1];
            if(i-1>=0 && j-1>=0 && s[i-1]!=t[j-1]) dp[i][j]-=dp[i-1][j-1];
            dp[i][j]=(dp[i][j]+MOD)%MOD;
        }
    }
    //rep(i,n+1) rep(j,m+1) cout<<"dp["<<i<<"]["<<j<<"]:"<<dp[i][j]<<endl;
    cout<<dp[n][m]<<endl;
}
