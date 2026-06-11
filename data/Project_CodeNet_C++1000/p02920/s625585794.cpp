
#include <numeric>
#include <iostream>
#include <sstream>
#include <vector>
#include <cstdio>
#include <map>
#include <set>
#include <functional>
#include <queue>
#include <string>
#include <bitset>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <set>
#include <algorithm>
#include <tuple>
#include <sstream>

using namespace std;

#ifdef LOCAL
#define logv(a) {cerr << #a << " = "; for (auto& e : a) {cerr << e << " ";} cerr << "\n";}
#define logvp(a) {cerr << #a << " = "; for (auto& e : a) {cerr << "(" << e.first << ", " << e.second << ") ";} cerr << "\n";}
#define logvv(a) {cerr << #a << " = \n"; for (auto& r : a) { for (auto& e : r) {cerr << e << " ";} cerr << "\n";} }
#define logvf(a, field) {cerr << #a"."#field << " = \n"; for (auto& e : a) { cerr << e.field << " ";} cerr << "\n"; }
#define logs(a) cerr << #a << " = " << (a) << "\n";
#define logss(a, b) cerr << #a << " = " << (a) << ", " << #b << " = " << (b) << "\n";
#define logp(a) cerr << #a << " = " << "(" << a.first << ", " << a.second << ")" << "\n";
#define cond(pred, stmt) if (pred) { stmt }
#else
#define logv(a)
#define logvp(a)
#define logvv(a)
#define logvf(a, field)
#define logs(a)
#define logss(a, b)
#define logp(a)
#define cond(pred, stmt)
#endif

#define forn(a, e) for (int a = 0; a < (int)(e); a++)
#define forr(a, s, e) for (int a = s; a < (int)(e); a++)

using i64 = long long;

template<typename T>
using Pair = array<T, 2>;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    i64 n;
    while (cin >> n) {
        vector<int> s(1<<n);
        priority_queue<int> q;
        map<int, vector<int>> id_by_s;
        forn(i, 1<<n) {
            cin >> s[i];
        }

        sort(s.begin(), s.end(), greater<int>());
        forn(i, s.size()) {
            id_by_s[s[i]].push_back(i);
        }

        vector<int> c(s.size());
        c[0] = n;
        forr(i, 1, s.size()) {
            c[i] = n - (int)floorl(log2l(i)) - 1;
        }

        bool ok = true;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> tb;
        id_by_s[s[0]].pop_back();
        tb.emplace(0, 0);

        for (auto it = id_by_s.rbegin(); it != id_by_s.rend(); ++it) {
            logv(it->second);
            vector<pair<int, int>> updates;
            for (auto i : it->second) {
                if (tb.empty()) {
                    ok = false;
                    break;
                }
                auto tc = tb.top();
                logss(s[tc.second], it->first);
                if (s[tc.second] <= it->first) {
                    ok = false;
                    break;
                }
                tb.pop();
                tc.first++;
                if (tc.first != n) {
                    tb.push(tc);
                    updates.emplace_back(tc.first, i);
                }
            }
            if (!ok) {
                break;
            }
            for (auto& upd : updates) {
                tb.push(upd);
            }
        }


        if (ok) {
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }
    }
}
