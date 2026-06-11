#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define rep(i, n) for (int i = 0; i < (n); ++i)
double const PI = 3.1415926535897932384626433;
using P = pair<int, int>;

int main() {
    ll x, a, b;
    cin >> x;
    a = (x / 500) * 1000;
    x = x - (x / 500) * 500;
    b = (x / 5) * 5;
    cout << a + b << endl;
    return 0;
}