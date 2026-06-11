#include <bits/stdc++.h>
#define rep(i, n) for(ll i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using ull = unsigned long long;
const double PI=acos(-1);

template<typename T>
istream& operator>> (istream& is, vector<T> &vec){
    for(T& x: vec) is >> x;
    return is;
}

int main(){
    ll n; cin >> n;
    if(n%2) cout << 0 << endl;
    else{
        ull ans = 0, a = 10;
        while(a <= n){
            ans += n/a;
            a *= 5;
        }
        cout << ans << endl;
    }
    return 0;
}