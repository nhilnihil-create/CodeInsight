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
    ll n,ans=0; cin>>n;
    vector<ll> p(n,0),pos(n+1,0);
    rep(i,n){
        cin>>p[i];
        pos[p[i]]=i;
    }
    set<ll> me;
    me.insert(pos[n]);
    me.insert(-1);
    me.insert(n);
    for(ll i=n-1;i>=1;i--){
        int l,r;
        r=*me.lower_bound(pos[i]);
        l=*(--me.lower_bound(r));
        if(r!=n){
            ans+=i*(pos[i]-l)*(*me.lower_bound(r+1)-r);
        }
        if(l!=-1){
            ans+=i*(r-pos[i])*(l-*(--me.lower_bound(l)));
        }
        me.insert(pos[i]);
    }
    cout<<ans<<endl;
}