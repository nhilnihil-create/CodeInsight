#include <bits/stdc++.h>

#define rr(i, b)    for (int i = 0; i < int(b); i++)
#define vi(n, a) vector <int> a(n); rr(i, n) cin >> a[i]
#define pvec(a) rr(i, a.size()) cout << a[i] << " "; cout << endl
#define bug(x) cout << #x << " " << x << endl
#define ll long long
#define vii vector <int>

using namespace std;

void solve() {
    ll a, x, b, y;
    cin >> a >> x >> b >> y;

    cout << max({x * y, a*b, a*y, b * x}) << endl;
}
 
int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    solve();
    return 0;
}