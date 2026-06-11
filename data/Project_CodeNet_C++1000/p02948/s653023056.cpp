// ABC137D.cpp :
// priority_queueを使う
#include <iostream>
#include <vector>
#include <queue>
using ll = long long;
#define rep( i, n ) for ( ll i = 0; i < (ll)( n ); ++i )
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> jobs(m);
    rep(i, n) {
        int a, b;
        cin >> a >> b;
        if (a > m) continue; // 支払日が遅いバイトはしない
        jobs.at(m - a).push_back(b);
    }
    priority_queue<int> q;
    ll ans = 0;
    for (int i = m - 1; i >= 0; i--) {
        for (int x : jobs.at(i)) {
            q.push(x);
        }
        if (!q.empty()) {
            ans += q.top(); q.pop();
        }
    }
    cout << ans << endl;
    return 0;
}
