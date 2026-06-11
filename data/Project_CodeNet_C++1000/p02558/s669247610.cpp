#include <bits/stdc++.h>
#include <atcoder/all>
using namespace atcoder;
using namespace std;
template <typename T> bool chmax(T &u, const T z) { if (u < z) {u = z; return true;} else return false; }
template <typename T> bool chmin(T &u, const T z) { if (u > z) {u = z; return true;} else return false; }
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define ll long long 
typedef pair<ll, ll> P;
const ll INF=1LL<<60;
ll gcd(ll x,ll y){return y? gcd(y,x%y) :x;}

int n,q,u,v;
int main(){
    cin>>n>>q;
    dsu d(n);
    rep(i,q){
        cin>>n>>u>>v;
        if(n)cout<<d.same(u,v)<<endl;
        else d.merge(u,v);
    }
}