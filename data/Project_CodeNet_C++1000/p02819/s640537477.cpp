#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i=0;i<ll(n);i++)
vector<bool> make_is_prime(int N) {
    vector<bool> prime(N + 1, true);
    if (N >= 0) prime[0] = false;
    if (N >= 1) prime[1] = false;
    for (int i = 2; i * i <= N; i++) {
        if (!prime[i]) continue;
        for (int j = i * i; j <= N; j += i) {
            prime[j] = false;
        }
    }
    return prime;
}
int main() {
    int x;
    cin >> x;
    int ans;
    vector<bool> p;
    p = make_is_prime(1e5 + 5);
    for (int i = x; i < 1e5 + 5; i++) {
        if (p[i]) {
            ans = i;
            break;
        }
    }
    cout << ans << endl;
    return 0;
}
