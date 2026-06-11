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
    vector<ll> a(n), bit(30, 0);
    ll b = 0;
    rep(i, n){
        cin >> a[i];
        b += a[i];
        rep(j, 30) if(a[i] & (1LL << j)) bit[j]++;
    }
    if(n%3 != 0 && b != 0){
        cout << "No" << endl;
        return 0;
    }
    rep(i, 30){
        if(bit[i] != 0 && bit[i] != 2*(n/3)){
            cout << "No" << endl;
            return 0;
        }
    }
    //for(auto i : bit) cout << i << " "; cout << endl;
    cout << "Yes" << endl;

    return 0;
}