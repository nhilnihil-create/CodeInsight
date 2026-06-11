#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int inf = 1000000;

int main() {
    ll N, M;
    ll ans = 0;
    cin >> N >> M;
    vector<pair<ll, ll>>p(N);
    priority_queue<ll>que;
    for (int i = 0; i < N; i++) {
        ll A, B;
        cin >> A >> B;
        p[i] = make_pair(A, B);
    }
    sort(p.begin(), p.end());
    ll a = 1;
    ll i = 0;
    while (a <= M) {
        while (i < N && p[i].first <= a) {
            que.push(p[i].second);
            i++;
        }
        a++;
        if (!que.empty()) {
            ans += que.top();
            que.pop();
        }
    }
    cout << ans << endl;
}
