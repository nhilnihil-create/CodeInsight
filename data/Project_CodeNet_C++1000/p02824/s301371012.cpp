#include <bits/stdc++.h>
using namespace std;
using ll=long long;
const ll INF=1001001001;
const ll LINF=1001001001001001001;
#define overload4(_1,_2,_3,_4,name,...) name
#define rep1(n) for(ll i=0;i<(n);++i)
#define rep2(i,n) for(ll i=0;i<(n);++i)
#define rep3(i,a,b) for(ll i=(a);i<(b);++i)
#define rep4(i,a,b,c) for(ll i=(a);i<(b);i+=(c))
#define rep(...) overload4(__VA_ARGS__,rep4,rep3,rep2,rep1)(__VA_ARGS__)
#define all(x) (x).begin(),(x).end()
#define vec vector<ll>
template<class T>bool chmax(T &a,const T &b){if(a<b){a=b;return 1;}return 0;}
template<class T>bool chmin(T &a,const T &b){if(b<a){a=b;return 1;}return 0;}

vec s;
void init(vec &a){
    s.push_back(0);
    for(ll x:a){
        s.push_back(x+s.back());
    }
}
ll query(ll from,ll to){
    return s[to+1]-s[from];
}

void solve(){
    ll n,m,v,p;
    cin>>n>>m>>v>>p;
    vec a(n);
    rep(i,n)cin>>a[i];
    sort(all(a));
    init(a);
    ll ans=p;
    rep(i,n-p){
        ll r=(v-p-i)*m;
        ll x=a[i]+m;
        if(x>=a[n-p]&&r<=(n-p-i)*x-query(i+1,n-p))ans++;
    }
    cout<<ans<<endl;
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(0);
    solve();
}
