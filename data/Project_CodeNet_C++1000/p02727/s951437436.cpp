#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const int INF = (1<<30) - 1;
const ll LINF = (1LL<<60) - 1;

int main(){
    int x, y, a, b, c;
    cin >> x >> y >> a >> b >> c;
    vector<int> p(a), q(b), r(c);
    for (int i = 0; i < a; ++i) {
        cin >> p[i];
    }
    for (int i = 0; i < b; ++i) {
        cin >> q[i];
    }
    for (int i = 0; i < c; ++i) {
        cin >> r[i];
    }
    sort(p.begin(), p.end(), greater<>());
    sort(q.begin(), q.end(), greater<>());
    priority_queue<int> que;
    for (int i = 0; i < x; ++i) {
        que.push(p[i]);
    }
    for (int i = 0; i < y; ++i) {
        que.push(q[i]);
    }
    for (int i = 0; i < c; ++i) {
        que.push(r[i]);
    }

    ll res = 0;
    for (int i = 0; i < x + y; ++i) {
        res += que.top();
        que.pop();
    }
    cout << res << endl;
}