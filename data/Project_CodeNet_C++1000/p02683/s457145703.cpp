#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const int INF = (1<<30) - 1;
const ll LINF = (1LL<<60) - 1;

int main(){
    int n, m, x;
    cin >> n >> m >> x;
    vector<int> c(n);
    vector<vector<int>> a(n, vector<int>(m));
    for (int i = 0; i < n; ++i) {
        cin >> c[i];
        for (int j = 0; j < m; ++j) {
            cin >> a[i][j];
        }
    }

    int res = INF;
    for (int i = 0; i < (1 << n); ++i) {
        vector<int> sum(m, 0);
        int cost = 0;
        for (int j = 0; j < n; ++j) {
            if (i & (1 << j)){
                for (int k = 0; k < m; ++k) {
                    sum[k] += a[j][k];
                }
                cost += c[j];
            }
        }

        bool flag = true;
        for (int j = 0; j < m; ++j) {
            if (sum[j] < x) flag = false;
        }

        if (flag) res = min(res, cost);
    }
    cout << (res == INF ? -1 : res) << endl;
}