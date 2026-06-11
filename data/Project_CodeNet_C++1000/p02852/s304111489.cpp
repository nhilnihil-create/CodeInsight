#include <bits/stdc++.h>
using namespace std;

#define rep(i,x) for(int i=0;i<(int)(x);++i)

using Int = long long;
int mo = 1e9+7;
int inf = 1e9;

int N, M;
string S;

signed main()
{
    cin >> N >> M >> S;

    vector<int> ans;

    reverse(begin(S), end(S));

    int cur = 0;

    while (cur < N) {
        int nx = cur;
        int n = 0;

        for (int i = 1; i <= M; ++i) {
            if (cur + i > N) break;
            if (S[cur + i] == '0') {
                nx = cur + i;
                n = i;
            }
        }

        if (cur == nx) {
            cout << -1 << endl;
            return 0;
        }

        cur = nx;
        ans.push_back(n);
    }

    reverse(begin(ans), end(ans));

    rep(i, ans.size()) {
        if (i) printf(" ");
        printf("%d", ans[i]);
    }
    printf("\n");

    return 0;
}
