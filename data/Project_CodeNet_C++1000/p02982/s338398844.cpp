#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;
using P = pair<int, int>;

int main() {

    int N, D;
    cin >> N >> D;
    int X[N][D];
    rep(i, N) rep(j, D) cin >> X[i][j];

    int ans = 0;
    for (int i = 0; i < N; ++i)
    {
        for (int j = i+1; j < N; ++j)
        {
            int norm = 0;
            for (int k = 0; k < D; ++k)
            {
                int diff = abs(X[i][k] - X[j][k]);
                norm += diff * diff;
            }
            bool flag = false;
            for (int k = 0; k <= norm; ++k)
            {
                if (k * k == norm)
                {
                    flag = true;
                }
            }
            if (flag) ans++;
        }
    }
    cout << ans << endl;
    return 0;
}