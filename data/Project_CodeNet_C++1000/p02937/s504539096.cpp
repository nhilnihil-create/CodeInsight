#include <bits/stdc++.h>
#include <math.h>

using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
typedef long long ll;
using Graph = vector<vector<int>>;
typedef long long ll;
typedef pair<int, int> P;

const int MOD = 1000000007;
const int INF_32 = 1LL << 30;
const int64_t INF_64 = 1LL << 60;

int main()
{
    string s, t;
    cin >> s;
    cin >> t;
    int n_s = s.size();
    int n_t = t.size();

    map<char, set<int>> mp;
    for (int i = 0; i < n_s; i++) {
        mp[s[i]].insert(i);
    }

    ll now = -1;
    ll cycle = 0;
    for (int i = 0; i < n_t; i++) {
        if (!mp.count(t[i])) {
            cout << -1 << endl;
            return 0;
        }
        auto it = mp[t[i]].upper_bound(now);
        if (it == mp[t[i]].end()) {
            now = *mp[t[i]].begin();
            cycle++;
            continue;
        } else {
            now = *it;
        }
    }

    cout << n_s * cycle + now + 1 << endl;
    return 0;
}