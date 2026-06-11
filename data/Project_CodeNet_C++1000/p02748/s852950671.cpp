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

int main(){
    ll a,b,m,ans; cin>>a>>b>>m;
    vector<ll> A(a,0),B(b,0);
    ll am=INF,bm=INF;
    rep(i,a){
        cin>>A[i];
        am=min(am,A[i]);
    }
    rep(i,b){
        cin>>B[i];
        bm=min(bm,B[i]);
    }
    ans=am+bm;
    rep(i,m){
        ll x,y,c; cin>>x>>y>>c;
        ans=min(ans,A[x-1]+B[y-1]-c);
    }
    cout<<ans<<endl;
}
