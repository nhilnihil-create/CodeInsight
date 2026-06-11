#include <bits/stdc++.h>
using namespace std;

//#define int long long
typedef long long ll;
//const int INF = 2e9;
//const ll INF = 9e18;


signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll S;
    cin >> S;
    ll x1 = 0, y1 = 0;
    ll x2 = 1e9, y2 = 1;
    ll x3, y3;
    if (S==1e18) x3 = 0, y3 = 1e9;
    else {
        y3 = S / (int)1e9 + 1;
        x3 = 1e9 - S % (int)1e9;
    }
    cout << x1 << " " << y1 << " ";
    cout << x2 << " " << y2 << " ";
    cout << x3 << " " << y3 << "\n";
}