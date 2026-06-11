#include <bits/stdc++.h>


using namespace std;


using ll = long long;


int main(void) {
    string S;

    cin >> S;

    vector<ll> remainders(2019, 0);
    remainders[0]++;

    ll cur = 0;
    ll base = 1;
    for (int i = S.length() - 1; i >= 0; i--) {
        cur += (S[i] - '0') * base;
        cur %= 2019;
        remainders[cur]++;
        base = base * 10 % 2019;
    }

    ll ans = 0;
    for (ll i = 0; i < 2019; i++) {
        ans += remainders[i] * (remainders[i] - 1) / 2;
    }
    cout << ans << endl;
}
