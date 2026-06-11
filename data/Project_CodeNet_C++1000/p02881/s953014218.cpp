#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = 1LL << 60;

int main() {
    ll n;
    cin >> n;
    ll ans;
    for (int i = 1; i <= sqrt(n); i++) {
        if (n % i == 0) {
            ans = i + n / i - 2;
        }
    }
    cout << ans << endl;
    return 0;
}