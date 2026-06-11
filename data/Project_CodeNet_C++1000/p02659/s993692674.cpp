#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define sz(x) int(x.size())
#define show(x) {for(auto i: x){cout << i << " ";} cout << endl;}
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
    ll A;
    double B;
    cin >> A >> B;
    B = round(100 * B);
    int C = (int)B;
    ll ans = A * C / 100;
    cout << ans << '\n';
    return 0;
}