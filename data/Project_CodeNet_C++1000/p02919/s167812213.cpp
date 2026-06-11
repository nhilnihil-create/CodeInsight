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
    ll n;
    cin >> n;
    multiset<int> s;
    s.insert(0);
    s.insert(0);
    s.insert(n + 1);
    s.insert(n + 1);
    vector<pair<int, int>> v(n);
    rep(i, n) {
        int tmp;
        cin >> tmp;
        v[i] = make_pair(tmp, i + 1);
    }
    sort(all(v));
    reverse(all(v));
    ll ans = 0;
    rep(i, n) {
        ll num = v[i].first;
        int id = v[i].second;
        auto it = s.lower_bound(id);
        int r1 = *it++;
        int r2 = *it--;
        it--;
        int l1 = *it--;
        int l2 = *it;
        ans += num * max(0, id - l1) * (r2 - r1);
        ans += num * max(0, r1 - id) * (l1 - l2);
        // printf("id=%d, num=%lld, r1=%d, r2=%d, l1=%d, l2=%d, ans=%lld\n", id, num, r1, r2, l1, l2, ans);
        s.insert(id);
    }
    cout << ans << endl;
    return 0;
}
