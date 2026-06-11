#define TEMPLATE_USED
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vl;
typedef vector<vl> vvl;
typedef pair<ll,ll> pl;
typedef vector<pl> vp;
const ll INF=1001001001;
const ll LINF=1001001001001001001;
const ll D4[]={0,1,0,-1,0};
const ll D8[]={0,1,1,0,-1,-1,1,-1,0};
#define _overload3(_1,_2,_3,name,...) name
#define _rep2(i,n) for(ll i=0;i<(n);++i)
#define _rep3(i,a,b) for(ll i=(a);i<(b);++i)
#define rep(...) _overload3(__VA_ARGS__,_rep3,_rep2)(__VA_ARGS__)
#define _repe2(i,n) for(ll i=0;i<=(n);++i)
#define _repe3(i,a,b) for(ll i=(a);i<=(b);++i)
#define repe(...) _overload3(__VA_ARGS__,_repe3,_repe2)(__VA_ARGS__)
#define _rrep2(i,n) for(ll i=(n)-1;i>=0;i--)
#define _rrep3(i,a,b) for(ll i=(b)-1;i>=(a);i--)
#define rrep(...) _overload3(__VA_ARGS__,_rrep3,_rrep2)(__VA_ARGS__)
#define all(x) (x).begin(),(x).end()
template<class T>
bool chmax(T &a,const T &b){if(a<b){a=b;return 1;}return 0;}
template<class T>
bool chmin(T &a,const T &b){if(b<a){a=b;return 1;}return 0;}
template<class T>
using pq=priority_queue<T,vector<T>,greater<T>>;

void solve();

int main(){
    cin.tie(0);
    ios::sync_with_stdio(0);
    solve();
}

void solve(){
    ll h,w;cin>>h>>w;
    vector<string> s(h);
    rep(i,h)cin>>s[i];

    vvl r(h,vl(w));
    rep(i,h)rep(j,w){
        if(s[i][j]=='#')continue;
        r[i][j]=(j?r[i][j-1]:0)+1;
        if(j==w-1||s[i][j+1]=='#'){
            ll id=j-1;
            while(id>=0&&s[i][id]=='.')r[i][id--]=r[i][j];
        }
    }
    vvl c(h,vl(w));
    rep(i,h)rep(j,w){
        if(s[i][j]=='#')continue;
        c[i][j]=(i?c[i-1][j]:0)+1;
        if(i==h-1||s[i+1][j]=='#'){
            ll id=i-1;
            while(id>=0&&s[id][j]=='.')c[id--][j]=c[i][j];
        }
    }

    ll ans=0;
    rep(i,h)rep(j,w){
        chmax(ans,c[i][j]+r[i][j]-1);
    }
    cout<<ans<<endl;
}