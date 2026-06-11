#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < n; ++i)
#define ll long long
#define P pair<int,int>
#define fast_io ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
const int MOD = 1000000007;
const int INF = 2002002002;
const ll LLINF = 9009009009009009009;
using namespace std;

int main() {
    fast_io
    int n, m;
    cin >> n >> m;
    vector<vector<int>> ab(100000);
    int a, b;
    rep(i,n) {
        cin >> a >> b;
        a--;
        ab[a].push_back(b);
    }
    priority_queue<int> que;
    ll ans = 0;
    for (int length = 1; length <= m; length++) {
        int index = length - 1;
        for (int pay: ab[index]) que.push(pay);
        if (que.empty()) continue;
        ans += que.top();
        que.pop();
    }
    cout << ans << endl;
    return 0;
}