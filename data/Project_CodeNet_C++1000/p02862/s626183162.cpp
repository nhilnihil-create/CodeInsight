//Knight

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
using p = pair<ll,ll>;
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
    int x,y;cin>>x>>y;
    if((x+y)%3!=0||min(x,y)*2<max(x,y)){
        cout<<0<<nnn;
        return 0;
    }

    //2a +  b = x
    //a  + 2b = y
    //
    //2a +  b = x
    //2a + 4b = 2y
    //3b = 2y - x
    //
    //4a + 2b = 2x
    //a  + 2b = y
    //3a = 2x - y
    int a=(2*x-y)/3;
    int b=(2*y-x)/3;
    int ans=1,wa=1;
    rep(i,0,min(a,b))ans=ans*(a+b-i)%mod;
    rep(i,0,min(a,b))wa=wa*(i+1)%mod;
    ans=ans*repsqr(wa,mod-2,mod)%mod;
    cout<<ans<<nnn;
    return 0;
}