//Bouquet

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
using p = pair<ll, string>;
using graph = vector<vector<ll>>;
const int inf = 2147483647;//2*10^9
const ll INF = 9223372036854775807;//9*10^18

int mod = 1000000007;

//n=元の数,p=乗数,m=mod
ll repsqr(ll n,ll p,ll m){
    if(p==0)return 1;
    if(p%2==0){
        ll t=repsqr(n,p/2,m);
        return t*t%m;
    }
    return n*repsqr(n,p-1,m)%m;
}

signed main (){
    int n,a,b;cin>>n>>a>>b;
    int ans = repsqr(2,n,mod)-1;
    int ax=1,bx=1,ay=1,by=1;
    rep(i,0,a){
        ax=ax*(n-i)%mod;
        ay=ay*(i+1)%mod;
    }
    rep(i,0,b){
        bx=bx*(n-i)%mod;
        by=by*(i+1)%mod;
    }
    ans=(ans-ax*repsqr(ay,mod-2,mod)-bx*repsqr(by,mod-2,mod))%mod;
    if(ans<0)ans=mod+ans;
    cout<<ans<<nnn;
    return 0;
}