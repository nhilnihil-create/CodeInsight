#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
    int N, M, Q;
    cin >> N >> M >> Q;
    vector<vector<ll>> Query(Q, vector<ll>(4));
    rep(i,Q) rep(j,4) cin >> Query[i][j];
    ll ans = 0;
    
    vector<bool> V;
    rep(i,N) V.push_back(0);
    rep(i,M-1) V.push_back(1);
    do {
        vector<int> A(N);
        int cnt0 = 0;
        int cnt1 = 0;
        rep(i,V.size()) {
            if (V[i] == 0) {
                ++cnt0;
                A[cnt0 - 1] = cnt1 + 1;
            } else ++cnt1; 
        }
        ll tmp = 0;
        rep(i,Q) if (A[Query[i][1] - 1] - A[Query[i][0] - 1] == Query[i][2]) tmp += Query[i][3];
        ans = max(ans, tmp);
    } while (next_permutation(V.begin(), V.end()));
    cout << ans << endl;
}