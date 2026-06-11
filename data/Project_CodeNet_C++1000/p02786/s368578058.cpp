#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int, int>;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)



int main() {
    ll h, ans = 0;
    cin >> h;
    for(ll i; h; i++) {
        h /= 2;
        ans += pow(2, i);
    }
    cout << ans << endl;
    return 0;
}