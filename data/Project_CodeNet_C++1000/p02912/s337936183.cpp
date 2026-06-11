#include <bits/stdc++.h>
#define DAU  ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define PLEC exit(0);
using namespace std;
#define int long long
priority_queue<int> q;
int n, m, x, sum;
main() {
    DAU
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        cin >> x;
        q.emplace(x);
    }
    while (m) {
        if (q.empty())
            m = 0;
        else {
            x = q.top() / 2;
            q.pop();
            --m;
            if (x > 0)
                q.emplace(x);
        }
    }
    while (!q.empty())
        sum += q.top(), q.pop();
    cout << sum;
    PLEC
}
