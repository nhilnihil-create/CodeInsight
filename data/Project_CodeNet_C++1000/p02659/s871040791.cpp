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
    int ib = 100 * B + 0.5;
    A *= ib;
    A /= 100;
    printf("%lld\n", A);
    return 0;
}