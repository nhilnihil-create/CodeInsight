#include <bits/stdc++.h>          
using namespace std;
typedef long long ll;

int main() {
    ll N;
    cin >> N;
    vector<ll> A(N);
    ll sum = 0;
    for (ll i=0; i<N; i++) {
        cin >> A[i];
        sum ^= A[i];
    }

    vector<ll> ans(N);
    for (ll i=0; i<N; i++) {
        ans[i] = sum^A[i];
    }
    for (ll i=0; i<N; i++) {
        cout << ans[i] << ' ';
    }
    cout << endl;
}