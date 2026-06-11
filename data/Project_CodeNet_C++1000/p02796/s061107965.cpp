#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<long long> vl;
typedef vector<bool> vb;
typedef vector<char> vc;
typedef vector<string> vs;
// #define INF __INT32_MAX__
#define INF 1e9
#define LINF __LONG_LONG_MAX__


int main() {
    int N; cin >> N;
    vector<pair<int, int>> G;

    rep(i, N) {
        int X, L; cin >> X >> L;
        auto p = make_pair(X + L, X - L);
        G.push_back(p);
    }

    sort(G.begin(), G.end());

    int cnt = 0;
    int prev = -INF;
    rep(i, N) {
        int r = G[i].first;
        int l = G[i].second;

        if (prev <= l) {
            prev = r;
            cnt++;
        }
    }

    cout << cnt << endl;
}
