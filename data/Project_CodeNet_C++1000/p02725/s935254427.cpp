#include <bits/stdc++.h>          
using namespace std;               
typedef long long ll;

int main() {
    ll K, N;
    cin >> K >> N;
    vector<ll> A(N);
    for (ll i=0; i<N; i++) {
        cin >> A[i];
    }

    sort(A.begin(),A.end());
    vector<ll> kankaku(N);
    kankaku[0] = (K-A[N-1]) + A[0];
    for (ll i=1; i<N; i++) {
        kankaku[i] = A[i] - A[i-1];
    }
    sort(kankaku.begin(),kankaku.end());
    ll ans = 0;
    for (ll i=0; i<N-1; i++) {
        ans += kankaku[i];
    }

    cout << ans << endl;
}