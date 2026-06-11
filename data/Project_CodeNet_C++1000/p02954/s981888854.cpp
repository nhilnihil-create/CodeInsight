#include <bits/stdc++.h>
using namespace std;

#define ln '\n'
#define REP(i, n) for (int i = 0; i < (int)(n); ++i)
#define FOR(i, a, b) for (int i = (a); i <= (int)(b); ++i)
#define FORR(i, a, b) for (int i = (a); i >= (int)(b); --i)
#define ALL(c) (c).begin(), (c).end()

typedef long long ll;
typedef vector<int> VI;
typedef vector<ll> VL;
typedef vector<VI> VVI;
typedef vector<VL> VVL;
typedef pair<int, int> P;
typedef pair<ll, ll> PL;
typedef vector<P> VP;
typedef vector<PL> VPL;
typedef vector<string> VS;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    string s;
    cin >> s;
    s += 'R';
    int n = s.size();
    VI ans(n - 1, 0);

    int target_i = -1;
    int r_count = 0;
    int l_count = 0;
    REP(i, n - 1) {
        if (s[i] == 'R')
            r_count++;
        else
            l_count++;

        if (s.substr(i, 2) == "RL") {
            target_i = i;
        } else if (s.substr(i, 2) == "LR") {
            ans[target_i] = (r_count + 1) / 2 + l_count / 2;
            ans[target_i + 1] = r_count / 2 + (l_count + 1) / 2;
            r_count = 0;
            l_count = 0;
        }
    }

    REP(i, ans.size()) {
        if (i == (int)ans.size() - 1)
            cout << ans[i] << ln;
        else
            cout << ans[i] << " ";
    }

    return 0;
}
