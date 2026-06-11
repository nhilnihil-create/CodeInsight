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

    int n = 0;
    cin >> n;
    vector<ll> v(n , 0);

    for(int i = 0; i <n; i++) {
        cin >> v[i];
    }

    sort(v.rbegin(), v.rend());
    ll ans = v[0];
    int j = 2;
    for(int i = 1; j < n; i++) {
        if(n - j >= 2) ans += 2 * v[i];
        else ans += v[i];
        j += 2;
    }
    cout << ans << endl;
    
    return 0;
}