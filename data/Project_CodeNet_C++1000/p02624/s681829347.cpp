#include <bits/stdc++.h>
using namespace std;

#define deb(x)        cerr << #x << " = " << x << "\n";
#define deb2(x, y)    cerr << #x << " = " << x << ", " << #y << " = " << y << "\n";
#define deb3(x, y, z) cerr << #x << " = " << x << ", " << #y << " = " << y << ", " << #z << " = " << z << "\n";

#define pb push_back
#define mp make_pair
#define F  first
#define S  second

#define all(x) x.begin(), x.end()
#define sz(x) (int)x.size()

typedef long long ll;  

void solve() {
    ll n;
    cin >> n;
    ll ans = 0;
    for (ll i = 1LL; i <= n; ++i) {
        ll x = n/i;
        ans += (x * (x + 1) * i) / 2;
    }
    cout << ans;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

//  freopen ("in.txt", "r", stdin);
//  freopen ("err.txt", "w", stderr); 
//  freopen ("out.txt", "w", stdout);

    ll tc = 1;
    //cin >> tc;

    while(tc--) {
        solve();
        cout << '\n';
    }

    return 0;
}
