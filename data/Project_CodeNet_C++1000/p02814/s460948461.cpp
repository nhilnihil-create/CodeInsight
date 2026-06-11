#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

ll gcd(ll a, ll b){
    if(a%b==0)return b;
    else return gcd(b, a%b);
}


ll lcm(ll x, ll y) {
    return (ll)x / gcd(x, y) * y;
}

int main(){
    int n, m;
    cin >> n >> m;
    vector<ll> a(n);
    rep(i,n) cin >> a[i];
    rep(i,n) a[i] /= 2;
    ll curlcm=a[0];
    for(int i=1; i<n; ++i){
        ll x = lcm(curlcm, a[i]) / curlcm;
        ll y = lcm(curlcm, a[i]) / a[i];
        if (x % 2 == 0 || y % 2 == 0) {
            cout << 0 << "\n";
            return 0;
        }
        curlcm = lcm(curlcm, a[i]);
        if (curlcm > m) {
            cout << 0 << "\n";
            return 0;
        }
    }
    cout << (m/curlcm+1)/2 << "\n";

}