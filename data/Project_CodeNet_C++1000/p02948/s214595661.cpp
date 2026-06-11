#include <algorithm>
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(), (x).end()
#define ll long long
#define INF 1000000000000000000

int main() {
    int N, M;
    cin >> N >> M;
    vector<vector<int>> A(pow(10, 5) + 5, vector<int>());
    rep(i, N) {
        int a, b;
        cin >> a >> b;
        a--;
        A[a].push_back(b);
    }

    ll ans = 0;
    priority_queue<ll> pq;
    for (int i = 0; i < M; i++) {
        if (A[i].size() != 0) {
            for (auto a : A[i]) {
                pq.push(a);
            }
        }
        if (!pq.empty())
            ans += pq.top(), pq.pop();
    }

    cout << ans << endl;
}