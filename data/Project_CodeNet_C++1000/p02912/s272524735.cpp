#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define REP(i, n) for (ll i = 0; i < (ll)(n); i++)
#define RREP(i, n) for (ll i = n - 1; i >= 0; i--)
#define FOR(i, a, b) for (ll i = a; i <= (ll)(b); i++)
#define RFOR(i, a, b) for (ll i = a; i >= (ll)(b); i--)
#define ALL(x) (x).begin(), (x).end()
#define MAX(x) *max_element(ALL(x))
#define MIN(x) *min_element(ALL(x))

template <typename T>
ostream &operator<<(ostream &os, const vector<T> &v) {
    os << "[";
    for (auto a : v) os << a << ", ";
    os << "]";
    return os;
}

int main() {
    ll N, M;
    cin >> N >> M;
    priority_queue<ll> que;
    REP(i, N) {
        ll a;
        cin >> a;
        que.push(a);
    }

    REP(i, M) {
        ll price = que.top() / 2;
        que.pop();
        que.push(price);
    }

    ll ans = 0;
    while (!que.empty()) {
        ans += que.top();
        que.pop();
    }
    cout << ans << endl;
    return 0;
}