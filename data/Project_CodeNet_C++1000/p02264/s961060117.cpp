#include <bits/stdc++.h>

using namespace std;

typedef long long  ll;

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);

    int n, q, time;
    string s;

    cin >> n >> q;
    queue<pair<int, string>> que;

    // Input
    for (int i = 0; i < n; ++i) {
        cin >> s >> time;
        que.push(make_pair(time, s));
    }

    int take_time = 0;
    while (!que.empty()) {
        pair<int, string> now = que.front(); que.pop();
        if (now.first - q <= 0) {
            take_time += now.first;
            cout << now.second << " " << take_time << "\n";
        }
        else {
            take_time += q;
            now.first -= q;
            que.push(now);
        }
    }

    return 0;
}