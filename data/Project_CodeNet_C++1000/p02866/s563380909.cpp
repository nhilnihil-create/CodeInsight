#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int mod = 998244353;

int main() {
    ll N;
    cin >> N;
    map<ll, ll>mp;
    vector<ll>D(N);
    for (int i = 0; i < N; i++) {
        cin >> D[i];
        mp[D[i]]++;
    }
    if (D[0] != 0) {
        cout << 0 << endl;
    } else {
        ll ans = 1;
        sort(D.begin(), D.end(), greater<ll>());
        for (int i = 0; i < N-1; i++) {
            ans *= mp[D[i]-1]; 
            ans %= mod;
        }
        cout << ans % mod << endl;
    }
}
