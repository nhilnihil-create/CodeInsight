#include <bits/stdc++.h>
using namespace std;

#define ALL(v) v.begin(), v.end()
#define V vector
#define P pair
#define ld long double
#define ll long long
#define mod 1000000007
#define IINF INT_MAX
#define INF 1LL << 30


int main() {
    ll n, k, q; cin >> n >> k >> q;
    V<ll> v(q);
    for(ll i = 0; i < q; i++){
        ll a; cin >> a;
        a--;
        v[i] = a;
    }

    V<ll> ans(n, k);
    for(int i = 0; i < q; i++){
        ans[v[i]]++;
    }

    for(int i = 0; i < n; i++){
        if(ans[i] - q <= 0) cout << "No" << endl;
        else cout << "Yes" << endl;
    }

    return 0;
}
