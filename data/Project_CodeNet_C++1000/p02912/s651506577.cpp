#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define rep(i,n) for (int i = 0; i < (n); i++)
#define sz(x) int(x.size())
const ll mod = 1000000007;
const ll INF = 10010010010010010;

int main() {
    int n,m,a; cin >> n >> m;
    priority_queue<int, vector<int>, less<int>> que;
    rep(i,n) {
        cin >> a;
        que.push(a);
    }
    rep(i,m) {
        a = que.top();
        que.pop();
        a /= 2;
        que.push(a);
    }
    ll ans = 0;
    rep(i,n) {
        a = que.top();
        que.pop();
        ans += a;
    }
    cout << ans << endl;
    return 0;
}
