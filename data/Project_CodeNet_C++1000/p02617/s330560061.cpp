/*input
10
5 3
5 7
8 9
1 9
9 10
8 4
7 4
6 10
7 2
*/

#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
using namespace std;
typedef long long ll;
typedef pair<int, int> P;

int main() {
    int N;
    cin >> N;
    vector<P> es(N-1);
    rep(i, N-1) {
        int u, v;
        cin >> u >> v;
        if (u > v) swap(u, v);
        es[i] = P(u, v);
    }
    // sort(es.begin(), es.end(), [](int x, int y) {
    //     return x.second-x.first < y.second-y.first;
    // });
    ll ans = 0;
    rep(i, N-1) ans -= (ll)es[i].first*(N-es[i].second+1);
    for (int i = 0; i <= N; i++) ans += (ll)i*(i+1)/2;
    cout << ans << endl;
}