//#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<n; ++i)
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
using namespace std;
using ll = int64_t;
using ld = long double;
using P = pair<int, int>;
using vs = vector<string>;
using vi = vector<int>;
using vvi = vector<vi>;
const int INF = 100010001;
const ll LINF = (ll)INF*INF*10;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    priority_queue<int> pq;
    rep(i, n) {
        int a;
        cin >> a;
        pq.push(a);
    }

    rep(i, m) {
        int now = pq.top();
        pq.pop();
        now >>= 1;
        pq.push(now);
    }

    ll ans = 0;
    while(!pq.empty()) {
        ans += pq.top();
        pq.pop();
    }

    cout << ans << endl;
}