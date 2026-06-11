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

ll n,m;
unordered_set<ll> s;

ll min_dist(ll x, ll y){
    if(x > y) swap(x, y);
    return min(y-x, x+n-y);
}

int main(){
    cin >> n >> m;
    ll j = 1;
    ll k = n;
    if(n%2 == 0) s.insert(n/2);
    for(ll i = 0;i < m;i++){
        ll d = min_dist(j, k);
        if(s.count(d)) j++;
        d = min_dist(j, k);
        // debug(d);
        s.insert(d);
        cout << j << " " << k << endl;
        j++;
        k--;
    }
}
