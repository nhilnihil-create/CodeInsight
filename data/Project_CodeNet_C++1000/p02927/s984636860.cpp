#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for(int i = 0; i < (n); i++)

int main()
{
    cin.tie(0); ios::sync_with_stdio(false);

    int M, D; cin >> M >>D;

    int ans = 0;
    for (int m = 4; m <= M; m++) {
        for (int d = 22; d <= D; d++) {
            int d1 = d%10;
            int d2 = d/10;
            if (d1 >= 2 && d2 >= 2 && m == d1 * d2) {
                ans++;
            }
        }
    }

    cout << ans << endl;
}
