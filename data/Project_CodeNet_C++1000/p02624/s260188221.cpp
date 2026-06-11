#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll,ll> P;

int main(){
    ll N;
    cin >> N;

    ll ans = 0;
    for (int i = 1; i <= N; i++) {
        ll tmp = N / i;
        ans += tmp * (tmp + 1) * i / 2;
    }

    cout << ans << endl;
    return 0;
}
