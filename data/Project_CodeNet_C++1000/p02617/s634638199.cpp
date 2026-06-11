#include <bits/stdc++.h>

#define debug(var)  do{std::cerr << #var << " : ";view(var);}while(0)
template<typename T> void view(T e){std::cerr << e << std::endl;}
template<typename T> void view(const std::vector<T>& v){for(const auto& e : v){ std::cerr << e << " "; } std::cerr << std::endl;}
template<typename T> void view(const std::vector<std::vector<T> >& vv){ for(const auto& v : vv){ view(v); } }
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
using namespace std;

typedef long long ll;
typedef long double ld;
typedef vector<ll> v1;
typedef vector<v1> v2;
typedef vector<v2> v3;

typedef unordered_map<ll, unordered_map<ll, ll>> graph;

const ll INF = 1ll << 50;
const ll mod = 1000000007;

ll n;
graph g;
ll a;
ll b;

int main(){
    cin >> n;
    for(ll i = 1;i < n;i++){
        ll u,v;
        cin >> u >> v;
        if(u > v) swap(u,v);
        g[u][v] = 0;
    }
    for(ll i = 1, j = n;i <= n;i++,j--){
        a += i*j;
    }
    // debug(a);
    for(ll i = 1;i <= n;i++){
        for(auto p : g[i]){
            ll j = p.first;
            b += i*(n-j+1);
        }
    }
    cout << a-b << endl;
}
