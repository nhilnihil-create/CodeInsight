#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
    int n;
    cin >> n;
    deque<int> a[n];
    for (int i = 0; i < n; i++) {
        for (int j = 0, t; j < n - 1; j++) {
            cin >> t;
            a[i].push_back(t - 1);
        }
    }
    queue<int> que;
    for (int i = 0; i < n; i++) que.push(i);
    int v = n * (n - 1) / 2;
    int day = 0;
    while (que.size()) {
        day++;
        queue<int> preQ;
        swap(preQ, que);
        bool used[n] = {};
        while (preQ.size()) {
            int x = preQ.front(); preQ.pop();
            if (a[x].size() && a[a[x].front()].size() && !used[x] && !used[a[x].front()] && a[a[x].front()].front() == x) {
                used[x] = used[a[x].front()] = true;
                que.push(x);
                que.push(a[x].front());
                a[a[x].front()].pop_front();
                a[x].pop_front();
                v--;
            }
        }
        if (v == 0) break;
    }
    if (v) cout << -1 << endl;
    else cout << day << endl;
}