#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define sz(x) int(x.size())
#define show(x) {for(auto i: x){cout << i << " ";} cout << endl;}
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
    ll A, B, N;
    cin >> A >> B >> N;
    if (N%B == 0) N--;
    ll x = min(B-1, N);
    ll ans = A * x / B - A * (x / B);
    cout << ans << '\n';
    return 0;
}