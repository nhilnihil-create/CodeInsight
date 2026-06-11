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

ll h,w;

ll ans = 0;

int main(){
    cin >> h >> w;
    if(h == 1 || w == 1){
        ans = 1;
    }else if(h%2 == 0){
        ans = h/2 * w;
    }else{
        if(w%2 == 0){
            ans = w/2 * h;
        }else{
            ans = (w-1)/2 * h + ((h-1)/2) + 1;
        }
    }
    cout << ans << endl;
}
