#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
    ll N;
    cin >> N;
    ll ans = (N)*(N+1)*(N+2)/6;
    for (int i = 0; i < N-1; i++) {
        ll a, b;
        cin >> a >> b;
        if (a > b) swap(a, b);
        ans -= (N-b+1)*a;
    }
    cout << ans << endl;
}