#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)n;i++)
#define rep1(i,n) for(int i=1;i<=(int)n;i++)
#define sp(n) cout << fixed << setprecision(n)
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
typedef long long ll;
using namespace std;
const ll inf = 1e9;
int main(void){
    int n,m;cin>>n>>m;
    vector<ll> dp(20000,inf);
    dp[0]=0;
    rep(i,m){
        int a,b;cin>>a>>b;
        int tmp=0;
        rep(j,b){
            int c;cin>>c;c--;
            tmp+=(1<<c);
        }
        for(int j=0;j<=(1<<n);j++){
            chmin(dp[j|tmp],dp[j]+a);
        }
    }
    if(dp[(1<<n)-1]==inf)cout<<-1<<endl;
    else cout<<dp[(1<<n)-1]<<endl;
}