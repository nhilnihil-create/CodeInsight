#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <string>
#include <numeric>
#include <cmath>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
#define FOR(a, b, c) for (int (a) = (b); (a) < (c); ++(a))
#define ROF(a, b, c) for (int (a) = (c) - 1; (a) >= (b); --(a))
#define REP(i, n) FOR(i, 0, n)
#define ALL(v) v.begin(), v.end()
#define SORT(v) sort(ALL(v))
#define REVERSE(v) reverse(ALL(v))

int main() {
    // A:
    /*char c;
    cin >> c;
    cout << char(c + 1) << endl;*/

    // B:
    /*int n, k, m;
    cin >> n >> k >> m;
    int s = 0;
    REP (i, n - 1) {
        int x; cin >> x; s += x;
    }
    int ans = (m * n) - s;
    if (ans >= 0 && ans <= k) cout << ans << endl;
    else if (ans < 0) cout << 0 << endl;
    else cout << -1 << endl;*/

    // C:
    /*int ac = 0, wa = 0, prob, subs;
    cin >> prob >> subs;
    vi completed;
    bool present = false;
    REP (i, subs) {
        int p;
        string S;
        cin >> p >> S;
        REP (j, completed.size()) {
            if (p == completed[j]) {
                present = true;
                break;
            }
        }
        if (!present) {
            if (S == "WA") {
                wa += 1;
            } else {
                ac += 1;
                completed.push_back(p);
            }
        }
        present = false;
    }
    cout << ac << " " << wa << endl;*/

    int n, m;
    cin >> m >> n;
    vi cnt(m);
    vector<bool> found(m);
    int WA = 0, AC = 0;
    REP (i, m) {
        cnt[i] = 0;
        found[i] = false;
    }
    REP (i, n) {
        int val; string S;
        cin >> val >> S;
        val--;
        if (S == "AC" && !found[val]) {
            found[val] = true;
            WA += cnt[val];
            AC += 1;
        } else {
            cnt[val]++;
        }
    }
    cout << AC << " " << WA << endl;
    return 0;
}
