#include <bits/stdc++.h>
#define rep(i,n) for (int i = 1; i <= (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
    int K;
    cin >> K;
    int ans = 0;

    rep(i,K) {
        rep(j,K) {
            rep(k,K) {
                ans += gcd(gcd(i, j), k);
            }
        }
    }
    cout << ans << endl;
}