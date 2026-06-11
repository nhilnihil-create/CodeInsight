#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
#define ALL(x) (x).begin(), (x).end()

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int N;
    cin >> N;
    if (N == 1) {
        cout << 1 << endl;
        return 0;
    }
    vector<pair<int, int>> xy(N);
    REP(i, N) {
        int x, y;
        cin >> x >> y;
        xy[i] = make_pair(x, y);
    }
    sort(ALL(xy));
    int ans = 1000000;
    for (int i = 0; i < N - 1; i++) {
        int xi, yi;
        tie(xi, yi) = xy[i];
        for (int j = i + 1; j < N; j++) {
            int xj, yj;
            tie(xj, yj) = xy[j];
            int p = xj - xi, q = yj - yi;
            set<pair<int, int>> st;
            int tmp = 0;
            REP(k, N) {
                if (st.count(xy[k]) == 0) {
                    tmp++;
                } else {
                    st.erase(xy[k]);
                }
                st.insert(make_pair(xy[k].first + p, xy[k].second + q));
            }
            ans = min(ans, tmp);
        }
    }
    cout << ans << endl;
}