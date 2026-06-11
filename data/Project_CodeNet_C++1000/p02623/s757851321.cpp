#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD=1000000007;
#define INF 1LL<<30
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define all(x) (x).begin(),(x).end()

int main(){
    int n,m;
    ll k;
    cin>>n>>m>>k;
    vector<ll> a(n),b(m);
    rep(i,n) cin>>a[i];
    rep(i,m) cin>>b[i];

    vector<ll> sa(n+1,0);
    vector<ll> sb(m+1,0);
    sa[0]=0;
    sb[0]=0;
    rep(i,n) sa[i+1]=sa[i]+a[i];
    rep(i,m) sb[i+1]=sb[i]+b[i];

    /*
    rep(i,n) cout<<sa[i]<<" ";
    cout<<endl;
    rep(i,m) cout<<sb[i]<<" ";
    cout<<endl;*/

    int ans=0;
    int id=m;
    rep(i,n+1){
        while(id>=0 && sa[i]+sb[id]>k){
            id--;
        }

        if(id<0) break;
        ans=max(ans,i+id);
    }

    cout<<ans<<endl;
}
