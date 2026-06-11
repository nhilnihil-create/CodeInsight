#include <bits/stdc++.h>

#define all(x) x.begin(), x.end()
using namespace std;
using ll = long long;
using pii = pair<int, int>;
const int MN = 1e5 + 5, LN = 17, MOD = 1e9 + 7, INF = 0x3f3f3f3f, BSZ = 320;
int N, p[MN], ind[MN];

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    cin >> N;
    set<int> s;
    for (int i = 1; i <= N; i++) {
        cin >> p[i];
        ind[p[i]] = i;
    }
    ll ret = 0;
    s.insert(ind[N]);
    for (int i = N - 1; i >= 1; i--) {
        int l, r, ll, rr;
        auto it = s.lower_bound(ind[i]);
        if (it == s.end()) r = N + 1, rr = N + 1;
        else {
            r = *it;
            it++;
            if (it == s.end()) rr = N + 1;
            else rr = *it;
        }
        it = s.lower_bound(ind[i]);
        if (it == s.begin()) l = 0, ll = 0;
        else {
            it--;
            l = *it;
            if (it == s.begin()) ll = 0;
            else it--, ll = *it;
        }
        s.insert(ind[i]);
        long long cnt = 0;
        cnt += 1LL * (rr - r) * (ind[i] - l);
        cnt += 1LL * (l - ll) * (r - ind[i]);
        ret += cnt * i;
    }
    cout << ret << '\n';
    return 0;
}
