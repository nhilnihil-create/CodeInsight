#include <bits/stdc++.h>
#define ll long long
#define ld long double
using namespace std;

int main() {
    ll S;
    cin >> S;
    ll x2 = 1e9, y2 = 1;
    ll x3 = (x2 - S % x2) % x2;
    ll y3 = (S + x3) / x2;
    cout << "0 0 " << x2 << " " << y2 << " " << x3 << " " << y3 << endl;
}
