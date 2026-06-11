#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    ll n =0;
    cin >> n;


    ll ans = 0;
    for(int i = 1; i <= n; i++) {
        ans += (i * ((n/i) * (n/i + 1))/2);
    }

    cout << ans << endl;

    return 0;
}