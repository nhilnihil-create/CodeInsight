#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
#define print(x) cout << x << endl;
using namespace std;
typedef long long ll;

int main()
{
    int N, M;
    cin >> N >> M;
    vector<int> v[100001];
    rep(i, N) {
        int a, b;
        cin >> a >> b;
        v[a].push_back(b);
    }

    int ans = 0;
    priority_queue<int> pq;
    for (int i = 1; i <= M; i++) {
        for (auto e : v[i]) pq.push(e);
        if (!pq.empty()) {
            ans += pq.top();
            pq.pop();
        }
    }

    cout << ans << endl;

    return 0;
}