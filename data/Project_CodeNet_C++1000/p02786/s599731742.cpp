#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int INF = 1001001001;


int main() {
    ll h;
    cin >> h;
    ll ans = 0, x = 1;
    while (h > 1) {
        ans += x;
        h /= 2;
        x *= 2;
    }
    ans += x;
    cout << ans << endl;
    return 0;
}