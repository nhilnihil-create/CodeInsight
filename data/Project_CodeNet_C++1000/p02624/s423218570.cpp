#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
 
const int M = 10000001;
ll a[M];
int main() {
    int N;
    cin >> N;
    fill(a, a + M, 1);
    for (ll i = 2; i < M; i++) {
        for (ll j = 1; i * j < M; j++) {
            a[i * j]++;
        }
    }
    ll ans = 0;
    for (ll i = 1; i <= N; i++) {
        ans += i * a[i];
    }
    cout << ans << "\n";
    return 0;
}