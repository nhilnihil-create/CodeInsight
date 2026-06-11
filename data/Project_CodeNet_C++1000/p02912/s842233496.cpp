#include <bits/stdc++.h>
using ll = long long;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define ALL(x) x.begin(),x.end()
using namespace std;


int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    int n,m;
    cin >> n >> m;
    priority_queue<int> q;
    rep (i, n) {
        int a;
        cin >> a;
        q.push(a);
    }
    rep (i, m) {
        int a = q.top();
        q.pop();
        q.push(a/2);
    }
    ll ans=0;
    while(!q.empty()) {
        ans += q.top();
        q.pop();
    }
    cout << ans << endl;
    return 0;
}