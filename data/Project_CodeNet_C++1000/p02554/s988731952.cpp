#include <bits/stdc++.h>

#define rr(i, b)    for (int i = 0; i < int(b); i++)
#define vi(n, a) vector <int> a(n); rr(i, n) cin >> a[i]
#define pvec(a) rr(i, a.size()) cout << a[i] << " "; cout << endl
#define bug(x) cout << #x << " " << x << endl
#define ll long long
#define vii vector <int>

using namespace std;

ll mod = 1e9 + 7;

void solve() {
    ll n;
    cin >> n;

    ll t = 1;
    ll nine = 1;
    ll eight = 1;
    
    for(int i = 0; i < n; i++) {
        t = (t * 10) % mod;
        nine = (nine * 9) % mod;
        eight = (eight * 8) % mod;
    }

    ll res = ((t - (2 * nine) % mod + eight) + mod) % mod;

    cout << res << endl;
}
 
int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    solve();
    return 0;
}