#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ll a, b, n;
    cin >> a >> b >> n;
    if (n < b) cout << a * n / b << endl;
    else cout << a * (b-1) / b << endl;
    return 0;
}