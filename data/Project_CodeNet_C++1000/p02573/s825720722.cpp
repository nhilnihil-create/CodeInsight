/*
    Only way to go is UP 
    H1s3nb3rg's Here !!
*/
#define _USE_MATH_DEFINES
#include <bits/stdc++.h> 
#include <cmath>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef vector<ll> vll;
typedef long double ld;
typedef pair<int,int> pi;
typedef uint64_t i64;
typedef vector<int> vi;
typedef vector<pi> vpi;
typedef vector<vector<ll>> v2ll;
const int MOD = 1e9+7;
#define FAST_IO ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define MAIN int main(){FAST_IO;ll tc;cin>>tc;while(tc--){solver();}ret0;}
#define MAIN1 int main(){FAST_IO;solver();ret0;}
#define rep(i,b,e) for(__typeof(e)i=(b)-((b)>(e));i!=(e)-((b)>(e));i+=1-2*((b)>(e)))
#define repa(i,x)  for(auto i:x)
#define vin(x) for(auto &i:x){cin>>i;}
#define vin1(x) for(ll i=1;i<x.size();i++){cin>>x[i];}
#define dbg(x) for(auto i:x){cout<<i<<" ";}cout<<ENDL;
#define dbg2(x) for(auto &i:x){for(auto j:i){cout<<j<<" ";}cout<<endl;}
#define dbgp(x) for(auto i:x){cout<<i.ff<<" "<<i.ss<<endl;}
#define ENDL "\n"
#define VALL(a) a.begin(),a.end()
#define ff first
#define ss second
#define sz(x) (int)x.size()
#define MP(a,b) make_pair(a,b)
#define ff first
#define ss second
#define ret0 return 0;
#define ret return;
#define pb(x) push_back(x)
/*----------------------------*/
ll fc(vector<ll> &v,ll n)
{
    if(v[n]<0)
        return n;
    return v[n]=fc(v,v[n]);
}
void uni(vector<ll> &v,ll a,ll b)
{
    ll x=fc(v,a);
    ll y=fc(v,b);
    if(x==y)
        return;
    v[x]+=v[y];
    v[y]=x;
    return;
}

void solver(){
    ll n ,r;
    cin>>n>>r;
    vll dsu(n+1,-1);
    while(r--){
        ll a,b;
        cin>>a>>b;
        uni(dsu,a,b);
    }
    ll res=-1;
    for(auto i:dsu)
        if(i<0)
            res=max(res,abs(i));
    cout<<res<<ENDL;
    ret;
}

MAIN1
