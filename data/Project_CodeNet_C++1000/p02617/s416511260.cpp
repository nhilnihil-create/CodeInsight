#include <bits/stdc++.h>
#pragma GCC optimize("O3")

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

int main(){

    long n;
    long u,v;
    long a;

    scanf("%ld", &n);
    a = n*(n+1)*(n+2)/6;
    for(ll i = 1;i < n;i++){
        scanf("%ld %ld", &u, &v);
        if(u < v) a -= u * (n-v+1);
        else a -= v * (n-u+1);
    }
    printf("%ld\n", a);
}
