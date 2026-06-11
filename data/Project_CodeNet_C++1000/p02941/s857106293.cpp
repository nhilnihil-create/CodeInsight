#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<long long> a(n), b(n);
    for (int i = 0; i < n; i++) {
        cin >> a.at(i);
    }
    for (int i = 0; i < n; i++) {
        cin >> b.at(i);
    }

    priority_queue<pair<long long, int>> que;
    for (int i = 0; i < n; i++) {
        if (a.at(i) < b.at(i)) que.push(make_pair(b.at(i), i));
    }

    auto prev = [&](int i){return (i + n - 1) % n;};
    auto next = [&](int i){return (i + 1) % n;};

    long long cnt = 0;
    while (!que.empty()) {
        auto p = que.top(); que.pop();
        int i = p.second;
        long long &x = b.at(i);

        long long y = b.at(prev(i)) + b.at(next(i));

        if (y > x) break;

        if ((x - a.at(i)) / y == 0) continue;

        cnt += (x - a.at(i)) / y;
        x -=  (x - a.at(i)) / y * y;

        if (a.at(i) < x) que.push(make_pair(x, i));
    }

    for (int i = 0; i < n; i++) {
        if (a.at(i) != b.at(i)) {
            cout << -1 << endl;
            return 0;
        }
    }
    cout << cnt << endl;
}