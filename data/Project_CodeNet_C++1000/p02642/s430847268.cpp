#include <bits/stdc++.h>

using namespace std;

using llong = long long int;

#define rep(i, n) for (int i = 0; i < n; ++i)
#define stl_rep(itr, x) for (auto itr = x.begin(); itr != x.end(); ++itr)
#define all(x) x.begin(), x.end()
#define allr(x) x.rbegin(), x.rend()

const static int MOD = 1000000007;
const static int INF = 1<<30;
const static int dx[4] = {1, 0, -1, 0};
const static int dy[4] = {0, 1, 0, -1};

int main (int argc, char *argv[]) {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int n;
    cin >> n;
    vector<int> A(n);
    map<int, int> M;
    rep(i, n) {
        cin >> A[i];
        ++M[A[i]];
    }

    sort(all(A));
    A.erase(unique(all(A)), A.end());
    n = static_cast<int>(A.size());

    int maxA = A[n - 1];
    vector<bool> check_table(maxA + 1, false);
    int k;
    rep(i, n) {
        k = 2;
        while (A[i]*k <= maxA) {
            check_table[A[i]*k] = true;
            ++k;
        }
    }

    int ans = 0;
    rep(i, (int)A.size()) {
        if (! check_table[A[i]] && M[A[i]] == 1) ++ans;
    }

    cout << ans << endl;

    return 0;
}