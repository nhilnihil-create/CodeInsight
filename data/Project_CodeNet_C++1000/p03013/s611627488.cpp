#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int, int>;

#define int ll

#define _GLIBCXX_DEBUG

#define REP(i,n) for (int i = 0; i < (n); ++i)
#define REPD(i,n) for (int i = (n-1); i >= 0; --i)
#define FORE(i, s, n) for (int i = (s); i <= (int)(n); i++)
#define debug(x) cerr << #x << ": " << x << '\n'
#define hyphen() cerr << "--\n"

#define ALL(vec) (vec).begin(), (vec).end()
#define REVALL(vec) (vec).rbegin(), (vec).rend()

#define fst first
#define pb push_back

const int MOD = (int)1e9 + 7;
const int INF = numeric_limits<int>::max();

signed main() {
    int N, M;

    cin >> N >> M;

    map<int, bool> mp;
    REP(i, M) {
        int A;
        cin >> A;
        mp[A] = true;
    }

    vector<int> ans(N+1);
    ans.at(0) = 1;
    if (mp.count(1)) {
        ans.at(1) = 0;
    } else {
        ans.at(1) = 1;
    }

    FORE(i, 2, N) {
        if (mp.count(i)) {
            ans[i] = 0;
            continue;
        }

        ans.at(i) = (ans.at(i-1) + ans.at(i-2)) % MOD;
    }

    cout << ans.at(N) << endl;
}
