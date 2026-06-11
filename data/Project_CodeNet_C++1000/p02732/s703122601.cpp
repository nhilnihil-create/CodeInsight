#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;

constexpr ll INF = ll(1e+18) + 1;

int main() {
    ll N;
    ll buf;
    ll sum = 0;

    cin >> N;
    vector<ll> a(N+1);
    vector<ll> b(N+1);

    rep(i, N) {
        cin >> buf;
        a[buf]++;
        b[i+1] = buf;
    }

    for (int i = 1; i <= N; i++) {
        sum += (a[i]*(a[i]-1))/2;
    }

    for (int i = 1; i <= N; i++) {
        if (a[b[i]] >= 3) {
            cout << sum - (a[b[i]]-1) << endl;
        } else if (a[b[i]] == 2) {
            cout << sum - 1 << endl;
        } else {
            cout << sum << endl;
        }
    }
    
}
