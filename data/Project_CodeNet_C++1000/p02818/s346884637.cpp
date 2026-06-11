#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const long long INF = 1LL<<60;

ll GCD(ll x,ll y){
    if(y == 0) return x;
    else return GCD(y,x%y);
}

ll LCM(ll a,ll b){
    return a / GCD(a,b) * b;
}

const int MOD = 1000000007;



int main() {
    ll a,b,k; cin >> a >> b >> k;
    ll ans1 = min(a,k);
    a -= ans1;
    k -= ans1;
    b -= min(b,k);
    cout << a << " " << b;
}
