#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < n; i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
    ll a, b, n;
    cin >> a >> b >> n;
    ll x = min(b - 1, n);
    cout << (a * (x % b) - ((a * x) % b)) / b << endl;
    return 0;
}