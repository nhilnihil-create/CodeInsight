#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll solve() {
    ll K, Q;
    cin >> K >> Q;
    //vector<ll> D(K), cd(K+1);
    vector<ll> D(K);
    for ( int i = 0; i < K; i++ ) {
        cin >> D[i];
        //cd[i+1] = cd[i] + D[i];
    }
    vector<ll> ans;
    ll N, X, M;
    for ( int q = 0; q < Q; q++ ) {
        cin >> N >> X >> M;
        vector<ll> cd(K+1);
        for ( int i = 0; i < K; i++ ) {
            cd[i+1] = cd[i] + (D[i] == 0 ? M : (((D[i]-1) % M) + 1));
        }
        ll y = X + ((N-1)/K) * cd[K] + cd[(N-1)%K];
        ll c = y/M - X/M;
        ans.push_back(N-1-c);
    }

    for ( int q = 0; q < Q; q++ ) {
        cout << ans[q] << "\n";
    }
    return 0;
}

int main() {
    solve();
    return 0;
}