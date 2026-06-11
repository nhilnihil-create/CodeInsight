#include <bits/stdc++.h>

#define debug(var)  do{std::cerr << #var << " : ";view(var);}while(0)
template<typename T> void view(T e){std::cerr << e << std::endl;}
template<typename T> void view(const std::vector<T>& v){for(const auto& e : v){ std::cerr << e << " "; } std::cerr << std::endl;}
template<typename T> void view(const std::vector<std::vector<T> >& vv){ for(const auto& v : vv){ view(v); } }

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
v1 x;

ll ans = INF;

int main(){
    cin >> n;
    x = v1(n);
    for(ll i = 0;i < n;i++){
        cin >> x[i];
    }
    for(ll i = 1;i <= 100;i++){
        ll mem = 0;
        for(ll j = 0;j < n;j++){
            mem += (x[j]-i)*(x[j]-i);
        }
        ans = min(ans,mem);
    }
    cout << ans << endl;
}
