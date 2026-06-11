//#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define pp pair<int,int>
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
#define ld long double
#define al(a) (a).begin(),(a).end()
#define mk make_pair
#define check cout<<"?"<<endl;

ll MOD=1000000007;
ll mod=998244353;
int inf=1000001000;
ll INF=1e18+5;

int main() {
    ll n,d,a,l,r,ce,ans=0; cin>>n>>d>>a;
    vector<pair<ll,ll>> m(n);
    vector<ll> sd(n+1,0);
    rep(i,n){
        ll x,h; cin>>x>>h;
        m[i]=mk(x,(h+a-1)/a);
    }
    sort(al(m));
    ll x,dd;
    rep(i,n){
        if(i!=0) sd[i]+=sd[i-1];
        if(m[i].second-sd[i]>0){
            dd=m[i].second-sd[i];
            ans+=dd;
            sd[i]+=dd;
            l=-1; r=n-1; x=m[i].first+2*d;
            while(l!=r){
                ce=(l+r+1)/2;
                if(x>=m[ce].first) l=ce;
                else r=ce-1;
            }
            sd[l+1]-=dd;
        }
    }
    cout<<ans<<endl;
}