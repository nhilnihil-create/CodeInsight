#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int x, y, a, b, c;

    cin >> x >> y >> a >> b >> c;

    priority_queue<int> p, q, r, all;
    int tmp;

    for(int i = 0; i < a; ++i) {
        cin >> tmp;
        p.emplace(tmp);
    }
    for(int i = 0; i < b; ++i) {
        cin >> tmp;
        q.emplace(tmp);
    }
    for(int i = 0; i < c; ++i) {
        cin >> tmp;
        r.emplace(tmp);
    }

    for(int i = 0; i < x; ++i) {
        all.emplace(p.top());
        p.pop();
    }
    for(int i = 0; i < y; ++i) {
        all.emplace(q.top());
        q.pop();
    }
    for(int i = 0; i < c; ++i) {
        all.emplace(r.top());
        r.pop();
    }

    long long ans = 0;

    for(int i = 0; i < x + y; ++i) {
        ans += all.top();
        all.pop();
    }

    printf("%lld\n", ans);

    return 0;
}