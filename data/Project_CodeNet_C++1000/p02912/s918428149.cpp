#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const int INF = (1<<30) - 1;
const ll LINF = (1LL<<60) - 1;

int main(){
    int n, m;
    cin >> n >> m;
    priority_queue<int> que;
    for (int i = 0; i < n; ++i) {
        int a;
        cin >> a;
        que.push(a);
    }

    for (int i = 0; i < m; ++i) {
        int ne = que.top();
        que.pop();
        que.push(ne/2);
    }

    ll res = 0;
    while (!que.empty()) {
        int v = que.top();
        res += (ll)v;
        que.pop();
    }
    cout << res << endl;
}