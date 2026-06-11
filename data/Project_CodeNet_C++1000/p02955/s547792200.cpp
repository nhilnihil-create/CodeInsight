#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include <boost/multiprecision/cpp_int.hpp>
//typedef boost::multiprecision::cpp_int ll;
typedef long double dd;
#define i_7 (ll)(1E9+7)
//#define i_7 998244353
#define i_5 i_7-2
ll mod(ll a){
    ll c=a%i_7;
    if(c>=0)return c;
    return c+i_7;
}
typedef pair<ll,ll> l_l;
ll inf=(ll)1E17;
#define rep(i,l,r) for(ll i=l;i<=r;i++)
#define pb push_back
ll max(ll a,ll b){if(a<b)return b;else return a;}
ll min(ll a,ll b){if(a>b)return b;else return a;}
void Max(ll &pos,ll val){pos=max(pos,val);}//Max(dp[n],dp[n-1]);
void Min(ll &pos,ll val){pos=min(pos,val);}
void Add(ll &pos,ll val){pos=mod(pos+val);}
dd EPS=1E-9;
#define fastio ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
///////////////////////////////////////

vector<l_l>fact(ll n){
    vector<l_l>v;
    for(ll i=2;i*i<=n;i++){
        ll c=0;
        if(n%i==0){
            while(n%i==0){
                n/=i;
                c++;
            }
            v.pb(l_l(i,c));
        }
    }
    if(n!=1)v.pb(l_l(n,1));
    return v;
}
ll len;
vector<l_l>v;
vector<ll>q;
void dfs(ll pos,ll val){
    if(pos==len){
        q.pb(val);return;
    }
    ll ne=val;
    rep(i,0,v[pos].second){
        dfs(pos+1,ne);
        ne*=v[pos].first;
    }
}

int main(){
    ll n,k;cin>>n>>k;
    ll a[n];rep(i,0,n-1)cin>>a[i];
    ll sum=0;
    rep(i,0,n-1)sum+=a[i];
    v=fact(sum);
    len=v.size();
    dfs(0,1);
    sort(q.begin(),q.end());
    reverse(q.begin(),q.end());
    //for(auto x:q)cout<<x<<" ";
    ll ans=1;
    for(auto x:q){
        vector<ll>mo;
        rep(i,0,n-1){
            if(a[i]%x==0)continue;
            mo.pb(a[i]%x);
        }
        sort(mo.begin(),mo.end());
        ll m=mo.size();
        if(m==0){
            Max(ans,x);continue;
        }
        ll b[m],c[m];
        b[0]=mo[0];
        rep(i,1,m-1)b[i]=b[i-1]+mo[i];
        rep(i,0,m-1)mo[i]=x-mo[i];
        c[m-1]=mo[m-1];
        for(ll i=m-2;i>=0;i--){
            c[i]=c[i+1]+mo[i];
        }
        
        rep(i,0,m-2){
            if(b[i]==c[i+1]){
                if(b[i]<=k){
                    Max(ans,x);
                }
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}















