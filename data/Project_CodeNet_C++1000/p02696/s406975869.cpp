#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define debug(x) cerr << "[(" << __LINE__ << ") " << (#x) << "]: " << x << endl;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    ll a, b, n;
    cin >> a >> b >> n;

    ll duh = min(b-1, n);
    cout << (a*duh)/b - a*(duh/b) << "\n";
}
