#include <algorithm>
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(), (x).end()
#define ll long long
#define INF 1000000000000000000

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int N, M;
    cin >> N >> M;
    priority_queue<ll> que;
    rep(i, N) {
        ll a;
        cin >> a;
        que.push(a);
    }

    rep(i, M) {
        ll q = que.top();
        que.pop();
        q /= 2;
        que.push(q);
    }

    ll ans = 0;
    while (!que.empty()) {
        ans += que.top();
        que.pop();
    }
    cout << ans << endl;
}