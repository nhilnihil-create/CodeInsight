#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vl;
typedef vector<vl> vvl;
typedef pair<ll,ll> pl;
typedef vector<pl> vp;
#define fore(i,a,b) for(ll i=(ll)(a);i<=(ll)(b);++i)
#define rep(i,n) fore(i,0,(n)-1)
#define rfore(i,a,b) for(ll i=(ll)(b);i>=(ll)(a);--i)
#define rrep(i,n) rfore(i,0,(n)-1)
#define all(x) (x).begin(),(x).end()
const ll INF=1001001001;
const ll LINF=1001001001001001001;
const ll D4[]={0,1,0,-1,0};
const ll D8[]={0,1,1,0,-1,-1,1,-1,0};
template<class T>
bool chmax(T &a,const T &b){if(a<b){a=b;return 1;}return 0;}
template<class T>
bool chmin(T &a,const T &b){if(b<a){a=b;return 1;}return 0;}

#define N 5005
ll d[N],d2[N];
void solve(){
    ll k,q;cin>>k>>q;
    rep(i,k)cin>>d[i];
    while(q--){
        ll n,x,m;cin>>n>>x>>m;
        rep(i,k)d2[i]=d[i]%m;
        ll cnt=0;
        ll sum=0;
        rep(i,k){
            sum+=d2[i];
            if(d2[i]==0)cnt++;
        }
        cnt*=(n-1)/k;
        sum=x%m+sum*((n-1)/k);
        rep(i,(n-1)%k){
            sum+=d2[i];
            if(d2[i]==0)cnt++;
        }
        cout<<n-1-cnt-sum/m<<endl;
    }
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(0);
    solve();
}
