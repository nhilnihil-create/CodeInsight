#include <bits/stdc++.h>
typedef long long ll; 
const ll mod = 1e9+7;
#define fo(i, n) for (int i = 0; i < n; i++)
#define sc(n) scanf("%d", &n) 
using namespace std;


ll sq(ll x) {return x*x;}

void solve() {
    ll a, b, c; cin >> a >> b >> c;
    bool yes;
    ll lhs = c-a-b;
    if (lhs <= 0) yes = false;
    else {
        ll k = lhs/2;
        if (lhs % 2) yes = k*k + k >= a*b;
        else yes = k*k > a*b;
    }
    if (yes) cout << "Yes";
    else cout << "No";
}

int main() {
    int t = 1;
    //scanf("%d", &t);
    while (t--) {
        solve();
    }
    return 0;
}