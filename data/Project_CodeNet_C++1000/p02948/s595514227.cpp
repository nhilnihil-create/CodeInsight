#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;
#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define REPR(i,n) for(int i=n; i>-1; --i)
#define ALL(a) (a).begin(),(a).end()
#define FILL(a,n,x); REP(i,(n)){ (a)[i]=(x); }
#define CINA(a,n); REP(i,(n)){ cin >> (a)[i]; }
#define FILL2(a,n,m,x); REP(i,(n)){ REP(j,(m)){(a)[i][j]=(x);} }
#define CINA2(a,n,m); REP(i,(n)){ REP(j,(m)){cin >> (a)[i][j];} }
#define Liny "Yes\n"
#define Linn "No\n"
#define LINY "YES\n"
#define LINN "NO\n"

#define umap unordered_map
//cout << setfill('0') << right << setw(4) << 12; // "0012"
int keta(ll x){ if(x<10){return 1;} else{return keta(x/10) + 1;}}
int keta_wa(ll x){ if(x<10){return x;} else{return keta_wa(x/10) + x%10;} }
int ctoi(char c){ return ( (c>='0' && c<='9')? c - '0': 0 );}
int __stoi(string s){ return atoi(s.c_str()); }
ll sum(ll a[],ll N){ return accumulate(a,a+N,0LL);}
ll gcd(ll a,ll b){if(a<b)swap(a,b); return b?gcd(b,a%b):a;}
ll lcm(ll a,ll b){if(a<b){swap(a,b);} return a/gcd(a,b)*b;}
template<class T> void chmax(T& a, T b){ if(a<b){a=b;} }
template<class T> void chmin(T& a, T b){ if(a>b){a=b;} }
const ll MOD = 1e9+7;

bool func(pair<ll,ll> x, pair<ll,ll> y){
    if(x.first!=y.first){ return x.first<y.first;}
    else{ return x.second>y.second; }
}

int main(){
    ll N,M; cin>>N>>M;
    pair<ll,ll> p[N];
    REP(i,N){
        ll a,b; cin>>a>>b;
        p[i]  = make_pair(a,b);
    }
    sort(p,p+N,func);
    int idx = 0;
    ll ans = 0;
    priority_queue<ll> cands;
    for(int i=1;i<=M;++i){
        while(1){
            if(idx==N || p[idx].first>i){ break;}
            cands.push(p[idx].second);
            ++idx;
        }
        if(!cands.empty()){
          ans += cands.top();
          cands.pop();
        }
    }
    cout << ans << "\n";
    
}
