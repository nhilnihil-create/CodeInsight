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
    vector<pii> v(n);
    for (int i = 0; i < n; ++i) {
        cin >> v[i].first >> v[i].second;
    }
    sort(all(v));

    priority_queue<int> que;
    int id = 0;
    ll res = 0;
    for (int i = m-1; i >= 0; --i) {
        if (id < n) {
            while (v[id].first <= m-i) {
                que.push(v[id].second);
                id++;
                if (id == n) break;
            }
        }
        if (que.empty()) continue;
        res += que.top();
        que.pop();
    }
    cout << res << endl;
}