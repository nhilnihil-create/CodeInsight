#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, a, b) for (int i = a; i < (int)(b); i++)
#define all(v) v.begin(), v.end()
const int MOD = 1e9 + 7;
const int INF = 1e9;
//'A' = 65, 'Z' = 90, 'a' = 97, 'z' = 122

int main() {
    int D; //365
    cin >> D;
    int c[26];
    rep(i, 0, 26) {
        cin >> c[i];
    }
    int s[D][26];
    rep(i, 0, D) {
        rep(j, 0, 26) {
            cin >> s[i][j];
        }
    }
    int t[D];
    rep(i, 0, D) {
        cin >> t[i];
        t[i]--;
    }
    ll score[D] = {};
    vector<int> last_day(26, -1);
    rep(i, 0, D) {
        if (i != 0) score[i] = score[i - 1];
        score[i] += s[i][t[i]];
        last_day[t[i]] = i;
        int decrease = 0;
        rep(j, 0, 26) {
            decrease += c[j] * (i - last_day[j]);
        }
        score[i] -= decrease;
    }
    rep(i, 0, D) {
        cout << score[i] << endl;
    }
    return 0;
}
