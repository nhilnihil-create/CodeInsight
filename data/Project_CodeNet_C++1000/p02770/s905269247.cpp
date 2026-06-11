#include<bits/stdc++.h>
using namespace std;
#define ALL(x) x.begin(),x.end()
#define rep(i,n) for(int i=0;i<(n);i++)
#define debug(v) cout<<#v<<":";for(auto x:v){cout<<x<<' ';}cout<<endl;
#define INF 1000000000
#define mod 1000000007
using ll=long long;
const ll LINF=1001002003004005006ll;
int dx[]={1,0,-1,0};
int dy[]={0,1,0,-1};
// ll gcd(ll a,ll b){return b?gcd(b,a%b):a;}
template<class T>bool chmax(T &a,const T &b){if(a<b){a=b;return true;}return false;}
template<class T>bool chmin(T &a,const T &b){if(b<a){a=b;return true;}return false;}

signed main(){
    cin.tie(0);
    ios::sync_with_stdio(0);
    
    int k,q;cin>>k>>q;
    vector<ll> d(k);
    rep(i,k) cin>>d[i];

    while(q--){
        ll n,x,m;cin>>n>>x>>m;
        vector<ll> e(k);
        ll sum=0;
        rep(i,k){
            e[i]=d[i]%m;
            sum+=e[i];
        }

        ll a1=0,a2=0;

        ll t=(n-1)/k;
        ll las=t*sum+x;
        rep(i,(n-1)%k) las+=e[i];
        a1=las/m-x/m;// マタギ

        rep(i,k){
            if(e[i]==0) a2+=t;
        }
        rep(i,(n-1)%k){
            if(e[i]==0) a2++;
        }
        cout<<n-1-a1-a2<<endl;
    }

    return 0;
}
