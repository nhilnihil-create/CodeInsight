#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <queue>
#include <string>
#include <set>
#include <bitset>
#include <unordered_map>
#include <cmath>

using namespace std;
using ll = long long;
using Pii = pair<int, int>;
using Pll = pair<ll, ll>;
template <class T>
using Vvec = vector<vector<T> >;

template <class T>
void debug(T& v)
{
    for(auto& x: v) cout << x << " ";
    cout << endl;
}

int main()
{
    ll k, q;
    cin >> k >> q;
    vector<ll> d(k);
    for(auto& x: d) cin >> x;
    vector<ll> n(q), x(q), m(q);
    for(int i=0; i<q; i++) cin >> n[i] >> x[i] >> m[i];

    for(int i=0; i<q; i++){
        ll s = x[i];
        ll u = 0, v = 0;
        ll r = (n[i]-1) % k;

        for(auto& x: d){
            u += x % m[i];
            if(x % m[i] == 0) u += m[i];
        }
        for(int j=0; j<r; j++){
            v += d[j] % m[i];
            if(d[j] % m[i] == 0) v += m[i];
        }
        s += (n[i]-1)/k * u + v;

        ll ans = (n[i]-1) - s/m[i] + x[i]/m[i]; 
        cout << ans << endl;
    }
}