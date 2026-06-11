#include <bits/stdc++.h>
#define ss second
#define ff first
#define all(x) x.begin(), x.end()

using namespace std;
using ll = long long;
using pii = pair<int, int>;

const int oo = 1e9 + 7;
const ll mod = 1e9 + 7;
const double PI = acos(-1);


int main (){
    ll n, ans = 0LL;

    cin >> n;

    vector<ll> count(62, 0LL);

    for (ll i=0; i<n; i++){
        ll a;
        cin >> a;
        bitset<62> b(a);
        for (ll j=0; j<62; j++){
            count[j] += b[j];
        }
    }

    for (ll i=0; i<62; i++){
        ans = (((((n - count[i])*(count[i]))%mod)*((1LL << i)%mod) + mod)%mod + mod + ans)%mod;
    }

    cout << ans << endl;
    return 0;
}