#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;

int main() {
    ll n, k;
    cin >> n >> k;
    ll x{n % k};
    x = min(x, abs(x - k));
    cout << x << endl;
}