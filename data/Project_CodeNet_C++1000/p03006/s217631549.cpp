#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for(int i = 0, i##_len = (n); i < i##_len; i++)
#define reps(i, s, n) for(int i = (s), i##_len = (n); i < i##_len; i++)
#define rrep(i, n) for(int i = (n) - 1; i >= 0; i--)
#define rreps(i, e, n) for(int i = (n) - 1; i >= (e); i--)
#define all(x) (x).begin(), (x).end()
#define sz(x) ((int)(x).size())
#define uniq(x) (x).erase(unique((x).begin(), (x).end()), (x).end())

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    // std::ifstream in("input.txt");
    // std::cin.rdbuf(in.rdbuf());
    int n;
    cin >> n;
    vector<pair<int, int>> s(n);
    rep(i, n) cin >> s[i].first >> s[i].second;
    set<pair<int, int>> pq;
    rep(i, n) {
        rep(ii, n) {
            if (i == ii) continue;
            pq.emplace(s[ii].first - s[i].first, s[ii].second - s[i].second);
        }
    }
    int mx = 0;
    for (auto v : pq) {
        int p = v.first;
        int q = v.second;
        int tmp = 0;
        rep(i, n) {
            pair<int, int> s1 = s[i];
            rep(ii, n) {
                if (i == ii) continue;
                pair<int, int> s2 = s[ii];
                if (s1 == s2) continue;
                if (((s2.first - s1.first) == p) && ((s2.second - s1.second) == q)) tmp++;
            }
        }
        mx = max(tmp, mx);
    }
    cout << (n - mx) << endl;
    return 0;
}
