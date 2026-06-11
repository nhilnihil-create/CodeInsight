#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
const ll INF = 100000000;
#define rep1(i, n) for (ll i=0; i<(n); i++) 
#define rep2(i, k, n) for (ll i=k; i<(n); i++)


int main() {
    ll a, b, n;
    cin >> a >> b >> n;
    ll ans = (a * (min(n, b-1)))/b;
    cout << ans << endl;
}