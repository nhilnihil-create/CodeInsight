#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i=0; i<n; i++)
#define pb push_back
#define int long long
typedef pair<int, int> P;
typedef tuple<int, int, int> T;

int N, K;
bool ban[110][110];

signed main() {
    //cin.tie(0); ios::sync_with_stdio(false);
    cin >> N >> K;
    if (K>N*(N-1)/2-(N-1)) {
        cout << -1 << endl;
        exit(0);
    }
    rep(i, N) rep(j, N) ban[i][j] = false;
    for (int i=1; i<N; i++) {
        for (int j=i+1; j<N; j++) {
            if (K==0) break;
            ban[i][j] = true;
            K--;
        }
    }
    vector<int> u, v;
    rep(i, N) for (int j=i+1; j<N; j++) {
        if (!ban[i][j]) {
            u.pb(i+1);
            v.pb(j+1);
        }
    }
    cout << u.size() << endl;
    rep(i, u.size()) cout << u[i] << " " << v[i] << endl;
}