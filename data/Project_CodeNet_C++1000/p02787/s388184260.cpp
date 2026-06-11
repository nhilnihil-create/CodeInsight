//Crested Ibis vs Monster

#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define int long long
#define rep(i,x,y) for(ll i=x;i<y;i++)
#define nvarep(n,a) ll n;cin>>n;vector<ll>a(n);rep(i,0,n)cin>>a[i]
#define vecrep(n,a,type) vector<type>a(n);rep(i,0,n)cin>>a[i]
#define lcm(a,b) (a/__gcd(a, b)*b)
#define range(a) (a).begin(),(a).end() 
#define pb push_back
#define mp make_pair
#define nnn "\n"
#define spa " "
using P = pair<ll, ll>;
using graph = vector<vector<ll>>;
const int inf = 2147483647;//2*10^9
const ll INF = 9223372036854775807;//9*10^18

signed main (){
    int h,n;cin>>h>>n;
    vector<P>s(n);
    rep(i,0,n){
        int a,b;cin>>a>>b;
        s[i]=mp(a,b);
    }
    vector<int>dp(h+1,inf);//体力をN減らすときの最小の体力
    dp[0] = 0;
    rep(i,1,h+1){
        int c;//来る前
        rep(j,0,n){
            c = i - s[j].first;
            if(c<0)c=0;
            dp[i]=min(dp[i],dp[c]+s[j].second);
        }
    }
    cout<<dp[h]<<nnn;
    return 0;
}