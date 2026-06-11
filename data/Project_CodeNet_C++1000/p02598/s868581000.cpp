#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;
using G = vector<vector<int>>;
    
int main(){
    ll n, k;
    cin >> n >> k;
    vector<ll> a(n);
    rep(i,n) cin >> a[i];
    ll l = 0, r = 1e9;
    ll mid = 0;
    while(r-l > 1){
        mid = (l+r)/2;
        auto f = [&](int x){
            ll count = 0;
            rep(i,n){
                count += ceil((double)a[i] / x) - 1;
                if(count>k) return false;
            }
            return true;
        };
        if(f(mid)) r = mid;
        else l = mid;
    }
    cout << r << endl;
    return 0;
}