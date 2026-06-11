#include <bits/stdc++.h>

using namespace std;

#define pos first
#define jumps second

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.in" , "r" , stdin);
#endif
    int n , m;
    string s;
    cin >> n >> m >> s;

    deque<pair<int , int> > dq;
    dq.push_back({n , 0});

    vector<int> par(n + 1);
    for (int i = n - 1 ;i >= 0 ;i--) {
        if (s[i] == '1') continue;

        while (dq.size() && dq.back().pos - i > m)
            dq.pop_back();

        while (dq.size() > 1 && dq[dq.size() - 2].jumps == dq.back().jumps)
            dq.pop_back();

        if (dq.empty()) {
            cout << -1;
            return 0;
        }

        par[i] = dq.back().pos;
        dq.push_front({i , dq.back().jumps + 1});
    }

    int cur = 0;
    while (cur != n) {
        cout << par[cur] - cur << ' ';
        cur = par[cur];
    }
}
