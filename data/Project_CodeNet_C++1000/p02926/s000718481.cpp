#include<bits/stdc++.h>
#include<unordered_set>
#include<unordered_map>
using namespace std;
#define int long long
#define REP(i,m,n) for(int i=(m);i<(n);i++)
#define rep(i,n) REP(i,0,n)
#define pb push_back
#define all(a) a.begin(),a.end()
#define rall(c) (c).rbegin(),(c).rend()
#define mp make_pair
#define endl '\n'
typedef long long ll;
typedef pair<ll,ll> pll;
typedef long double ld;
const ll inf=1e9+7;
const ll mod=1e9+7;
double PI=acos(-1.0);
signed main(){
    ll n;cin>>n;
    vector<pair<double,pll> >a(0);
    rep(i,n){
        ll x,y;cin>>x>>y;
        double c=atan2(y,x);
        a.pb(mp(c,mp(x,y)));
        a.pb(mp(c+2*PI,mp(x,y)));
    }
    ll ans=0;
    sort(all(a));
    rep(i,n){
        ll cntx=0;
        ll cnty=0;
        REP(j,i,i+n){
            cntx+=a[j].second.first;
            cnty+=a[j].second.second;
            ans=max(ans,cntx*cntx+cnty*cnty);
        }
    }
    cout<<fixed<<setprecision(16)<<sqrt(ans)<<endl;
}