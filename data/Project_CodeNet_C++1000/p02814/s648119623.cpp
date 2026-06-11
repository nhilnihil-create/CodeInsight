#include <bits/stdc++.h>
#define ss second
#define ff first
#define all(x) x.begin(), x.end()
 
using namespace std;
using ll = long long;
using pii = pair<int, int>;
 
const int oo = 1e9 + 7;
const int mod = 1e9 + 7;
const double PI = acos(-1);

ll lcm(ll a, ll b){
    ll ans = a*b;
    return (ans)/(__gcd(a, b));
}
 
 
int main (){
    ll n, m, resto = 0, mul=1, x;

    cin >> n >> m;

    set<ll> v;

    for (int i=0; i<n; i++) {
        cin >> x;
        x/=2;
        v.insert(x);
        mul = x;
    }
    for (auto x: v){
        mul = lcm(mul, x);
    }
    for (auto x: v) resto+= (mul/x)%2;
    if (resto != (int)v.size()){
        cout << 0 << endl;
        return 0;
    }

    ll ans = (m/mul)/2 + (m/mul)%2;
    cout << ans << endl;
    return 0;
}