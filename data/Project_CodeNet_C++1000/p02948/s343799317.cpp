
//----------------------------------------------------------------------
#include <bits/stdc++.h>
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)   FOR(i,0,n)
//----------------------------------------------------------------------

using namespace std;
using ll = long long;
using P = pair<int,int>;
using Graph = vector<vector<int>>;

int main(void) {
    int n, m;
    cin >> n >> m;

    Graph freq(m+1);
    REP(i, n) {
        int a, b;
        cin >> a >> b;
        if(a > m) continue;
        freq[a].push_back(b);
    }
    priority_queue<int> q;
    ll ans = 0;
    for(int i = m-1; i >= 0; --i) {
        for(int v : freq[m - i]) {
            q.push(v);
        }
        if(!q.empty()) {
            ans += q.top(); q.pop();
        }
    }
    cout << ans << endl;
    return 0;
}