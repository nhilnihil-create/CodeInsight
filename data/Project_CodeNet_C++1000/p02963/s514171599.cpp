#include <bits/stdc++.h>
#define rep(i, n) for(ll i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
const double PI=acos(-1);

template<typename T>
istream& operator>> (istream& is, vector<T> &vec){
    for(T& x: vec) is >> x;
    return is;
}

int main(){
    ll n; cin >> n;
    ll maxx = 1000000000, x = (maxx-n%maxx)%maxx, y = (n+x)/maxx;
    printf("%lld %lld %lld %lld %lld %lld\n", 0LL, 0LL, maxx, 1LL, x, y);
    return 0;
}