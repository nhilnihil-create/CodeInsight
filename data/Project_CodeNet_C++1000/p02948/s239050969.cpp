
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

const int N = 1e5 + 5;
int n, m;
ii a[N];
priority_queue<int, vector<int>, greater<int>> que;
ll res;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        cin >> a[i].first >> a[i].second;
    }
    sort(a, a + n, greater<ii>());
    for (int i = 0; i < n; ++i) {
        int p = a[i].second;
        if (que.size() + a[i].first <= m) {
            res += p;
            que.push(p);
        } else if (!que.empty() && p > que.top()) {
            res -= que.top();
            res += p;
            que.pop();
            que.push(p);
        }
    }
    cout << res << endl;
    return 0;
}

