#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define rep(i,n) for (int i = 0; i < (n); i++)
const ll mod = 1000000007;

int main() {
    int n,m; cin >> n >> m;
    int a,b;
    priority_queue<int, vector<int>, less<int>> pq;
    vector<pair<int, int>> t;
    rep(i,n) {
        cin >> a >> b;
        t.push_back({m-a,b});
    }
    sort(t.begin(), t.end());
    //rep(i,n) cout << t[i].first << " " << t[i].second << endl;
    ll ans = 0;
    int pqlen = 0;
    for (int i = m-1; i >= 0; i--) {
        while (n > 0 && i == t[n-1].first) {
            pq.push(t[n-1].second);
            t.pop_back();
            n--;
            pqlen++;
        }
        if (pqlen > 0) {
            ans += pq.top();
            pq.pop();
            pqlen--;
        }
    }
    cout << ans << endl;
    return 0;
}
