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
#define snd second
#define pb push_back

const int MOD = (int)1e9 + 7;
const int INF = numeric_limits<int>::max();

signed main() {
    int N, M;

    cin >> N >> M;

    // vector<int> As(N);
    // REP(i, N) {
    //     cin >> As.at(i);
    // }

    // その時点で一番高いものにチケットを適用していく
    // 途中ではdoubleで持っておく
    priority_queue<double> costs;
    REP(i, N) {
        int A;
        cin >> A;

        costs.push(A * 1.0);
    }

    REP(m, M) {
        int a = costs.top();
        costs.pop();

        costs.push(a / 2.0);
    }

    // 計算
    int ans = 0;
    while(!costs.empty()) {
        int c = costs.top();
        costs.pop();

        ans += c;
    }

    cout << ans << endl;

}
