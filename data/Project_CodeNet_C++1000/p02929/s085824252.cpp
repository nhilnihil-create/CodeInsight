#include<bits/stdc++.h>
using namespace std;

#define MOD 1000000007
#define ll long long int
#define vll vector<ll>

int main() {

    ll N;
    cin >> N;

    string S;
    cin >> S;

    vll B(200005);
    B[0] = 1;
    for (ll i = 1; i < 2*N; i++) {
        if (S[i] == S[i-1]) {
            B[i] = 1 - B[i-1];
        }
        else B[i] = B[i-1];
    }

    ll sum = 0;
    for (ll i = 0; i < 2*N; i++) {
        sum += B[i];
    }

    if (sum != N || S[0] == 'W' || S[2*N-1] == 'W') {
        cout << 0 << endl;
        return 0;
    }

    ll count = 0;
    ll ans = 1;
    for (ll i = 0; i < 2*N; i++) {
        if (B[i] == 0) {
            ans *= count;
            ans %= MOD;
            count--;
        }
        else count++;
    }

    for (ll i = 1; i <= N; i++) {
        ans *= i;
        ans %= MOD;
    }

    cout << ans << endl;

    return 0;
}
