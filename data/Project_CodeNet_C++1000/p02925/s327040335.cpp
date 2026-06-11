#include <bits/stdc++.h>
using ll = long long;
using namespace std;

int main()
{
    int n; cin >> n;
    vector<queue<int>> a(n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n - 1; j++) {
            int aij; cin >> aij; aij--;
            a[i].push(aij);
        }
    }

    int ans = 0;

    queue<int> check;
    for (int i = 0; i < n; i++) check.push(i);
    while (true) {
        bool possible = false;
        bool end = true;
        vector<bool> seen(n, false);
        queue<int> check_next;
        while (!check.empty()) {
            int i = check.front(); check.pop();
            if (!a[i].empty()) {
                end = false;

                if (seen[i]) {
                    continue;
                }

                seen[i] = true;
                int op = a[i].front();
                if (!a[op].empty() && i == a[op].front() && !seen[op]) {
                    possible = true;
                    seen[op] = true;
                    a[i].pop();
                    a[op].pop();
                    check_next.push(i);
                    check_next.push(op);
                }
            }
        }
        if (end) break;

        if (!possible) {
            ans = -1;
            break;
        }

        ans++;
        check = check_next;
    }

    cout << ans << endl;
    return 0;
}