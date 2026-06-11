#include<bits/stdc++.h>
using namespace std;
#define int long long
#define REP(i,m,n) for(int i=(m);i<(n);i++)
#define rep(i,n) REP(i,0,n)
#define pb push_back
#define all(a) a.begin(),a.end()
#define rall(c) (c).rbegin(),(c).rend()
#define mp make_pair
#define endl '\n'
#define vec vector<ll>
#define mat vector<vector<ll> >
#define fi first
#define se second
typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll,ll> pll;
typedef long double ld;
typedef complex<double> comp;
const ll inf=1e9+7;
const ll mod=1e9+7;
const int MAX=1010;


signed main(){
    ll h,w,m;cin>>h>>w>>m;
    set<pll>st;
    map<ll,ll>x,y;
    ll mx=0,my=0;
    rep(i,m){
        ll a,b;cin>>a>>b;
        x[a]++;
        y[b]++;
        mx=max(mx,x[a]);
        my=max(my,y[b]);
        st.insert(mp(a,b));
    }
    ll cnt=0;
    vector<ll>used(w+1);
    for(auto e:st){
        if(y[e.se]==my&&x[e.fi]==mx){
            cnt++;
        }
    }
    ll cntx=0;
    ll cnty=0;
    for(auto e:x){
        if(e.se==mx)cntx++;
    }
    for(auto e:y){
        if(e.se==my)cnty++;
    }
    cout<<mx+my-(!(cntx*cnty>cnt))<<endl;
}