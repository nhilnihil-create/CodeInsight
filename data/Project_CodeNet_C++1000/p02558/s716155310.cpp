#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

typedef long long ll;
typedef pair<ll,ll> P;
typedef pair<P,ll> PLL;
typedef pair<P,P> PP;
typedef vector<ll> llVEC;
typedef vector<P> PVEC;
typedef priority_queue<P,PVEC,greater<P> > PPQ;
typedef priority_queue<ll, llVEC, greater<ll> > llPQ;

#define rep(i,a,n) for(ll i = a;i < n;i++)
#define rrep(i,a,n) for(ll i = n-1; i >= a;i--)
#define index_check(i,n) if(i > n-1 || i < 0) continue;
#define LINF (ll)1e18
#define INF (int)1e9
#define fs first
#define sc second

template<typename T>
ll sz(vector<T> &vec){ return (ll)vec.size(); }
ll sz(string &s){ return (ll)s.size(); }
ll gcd(ll a,ll b){ return ((!b) ?a :gcd(b, a%b)); }
ll lcm(ll a,ll b){ return a / gcd(a,b) * b; }

int main(){
    ll n,q;
    cin >> n >> q;
    dsu d(n);

    ll t,u,v;
    rep(i,0,q){
        cin >> t >> u >> v;
        if(t == 0){
            d.merge(u,v);
        }
        else{
            cout << d.same(u,v) << endl;
        }
    }
    return 0;
}
