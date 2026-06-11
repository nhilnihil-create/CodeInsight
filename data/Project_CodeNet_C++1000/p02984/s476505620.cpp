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
    vector<ll> a(n);
    ll sum = 0;
    rep(i, n){
        cin >> a[i];
        sum += a[i];
    }
    ll ans = sum;
    for(ll i = 1; i < n; i += 2){
        ans -= 2*a[i];
    }
    rep(i, n){
        if(i > 0) cout << " ";
        if(i != 0) ans = 2*a[i-1] - ans;
        cout << ans;
    }
    cout << endl;
    return 0;
}