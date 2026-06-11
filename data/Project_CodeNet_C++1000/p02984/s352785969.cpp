#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < n; i++)
#define all(v) v.begin(), v.end()
using ll = long long;
const int inf = int(1e9);
//const ll inf = ll(1e19);
const int mod = int(1e9) + 7;

int main(){
    ll n, a[int(1e5)];cin >> n;
    rep(i, n) cin >> a[i];

    ll x1 = 0;
    rep(i, n){
        if(i%2 == 0) x1 += a[i];
        else x1 -= a[i];
    }
    
    cout << x1 << ' ';
    ll pre = x1;
    rep(i, n - 1){
        pre = 2*(a[i] - pre/2);
        cout << pre << ' ';
    }
    cout << endl;
}