#include <bits/stdc++.h>

using namespace std;


int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n;
    long long d, v;
    cin >> n >> d >> v;
    vector<pair<long long, long long>> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i].first >> a[i].second;
    }
    sort(a.begin(), a.end());
    deque<pair<long long, long long>> q;
    long long tot = 0;
    long long ans = 0;
    for (auto pr: a) {
        while (q.size() > 0 && pr.first > q.front().first) {
            tot -= q.front().second;
            q.pop_front();
        }
        if (tot < pr.second) {
            auto r = pr.second - tot;
            auto cnt = r/v + (r%v > 0 ? 1 : 0);
            auto cur = cnt*v;
            tot += cur;
            ans += cnt;
            q.push_back({pr.first + 2*d, cur});
        }
    }
    cout << ans << endl;
}

