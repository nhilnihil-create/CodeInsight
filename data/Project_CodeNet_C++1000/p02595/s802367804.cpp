#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define PI 3.14159265359
#define rep(i,n) for(int i=0;i<(n);i++)

int main() {
    ll n, d, ans = 0;
    vector<ll> x(200010), y(200010);
    cin >> n >> d;
    rep(i, n) cin >> x[i] >> y[i];
    
    rep(i,n){
        ll hoge = x[i] * x[i] + y[i] * y[i];
        if(hoge <= d*d)
            ans++;
    }
    cout << ans << endl;
    return 0;
}