#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)(n);i++)
using namespace std;
using ll = long long ;
using P = pair<int,int> ;
using pll = pair<long long,long long>;
constexpr int INF = 1e9;
constexpr long long LINF = 1e17;
constexpr int MOD = 1000000007;
constexpr double PI = 3.14159265358979323846;

ll dp[5000];

int main(){
    rep(i,5000) dp[i]=LINF; 
    int n,m;
    scanf("%d%d",&n,&m);
    vector<ll> money(m),get(m);
    rep(i,m){
        ll a;
        int b;
        scanf("%lld%d",&a,&b);
        ll res=0;
        rep(j,b){
            int c;
            scanf("%d",&c);
            --c;
            res+=1<<c;
        }
        money[i]=a;
        get[i]=res;
    }
    dp[0]=0;
    rep(i,m){
        for(int bit=0;bit<(1<<n);bit++){
            dp[bit|get[i]] = min(dp[bit]+money[i],dp[bit|get[i]]);
        }
    }
    printf("%lld\n",(dp[(1<<n)-1]==LINF?-1:dp[(1<<n)-1]));
    return 0;
}