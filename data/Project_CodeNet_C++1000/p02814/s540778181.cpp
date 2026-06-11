#include<iostream>
#include<string>
#include<vector>
#include<map>
#include<unordered_map>
#include<set>
#include<unordered_set>
#include<numeric>
#include<algorithm>
#include<tuple>
#include<cmath>
#include <iomanip>

typedef unsigned long long ull;
typedef long long ll;

ll DENOM = 1000000000LL + 7LL;

using namespace std;

ll n, m, k;
ll h, w;

ll calc_gcd(ll x, ll y){
    if(y>x){
        ll z = x;
        x = y;
        y = z;
    }
    while( y > 0){
        ll z = x % y;
        x = y;
        y = z;
    }
    return x;
}

int main(){
    cin >> n >> m;
    vector<ll> a(n);
    for (ll i=0; i<n; ++i){
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    ll x  =a[0];
    ll y = 1;
    while(x % 2 == 0){
        y *= 2;
        x /=2;
    }
    ll lcm = a[0] / y;
    for (ll i=1; i<n; ++i){
        if ( (a[i] % y != 0) || ((a[i]/y) %2 == 0)){
            cout << 0 << endl;
            return 0;
        }
        ll b = a[i] / y;
        lcm = (b * lcm) / calc_gcd(lcm, b);
    }
    lcm = lcm * y / 2;
    ll ret = m / lcm;
    ret = (ret / 2) + (ret % 2);
    cout << ret << endl;
    return 0;
}