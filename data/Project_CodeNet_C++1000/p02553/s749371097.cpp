#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main () {
    ll a, b, c, d;
    cin >> a >> b >> c >> d;
    cout << max({a*c, b*c, a*d, b*d}) << endl;
}