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
    vector<ll> c(n), l(n), r(n);
    vector<pair<ll, ll>> xl(n);
    rep(i, n){
        ll x, a; cin >> x >> a;
        xl[i].first = x+a;
        xl[i].second = x-a;
    }
    sort(xl.begin(), xl.end());
    ll pos = -1000000000, cnt = 0;
    rep(i, xl.size()){
        if(pos <= xl[i].second){
            pos = xl[i].first;
            cnt++;
        }
    }
    cout << cnt << endl;
    return 0;
}