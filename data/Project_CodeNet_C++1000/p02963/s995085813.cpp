#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
using namespace std;

typedef long long ll;

int main() {
    ll S;
    cin >> S;
    ll x = 1e9, y = (S + x - 1) / x, a = 1, b = x * y - S;
    cout << "0 0 " << b << " " << y << " " << x << " " << a << "\n";
}