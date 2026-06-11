#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); i ++)
using namespace std;
typedef long long ll;
typedef pair<ll,ll> PL;
typedef pair<int,int> P;
const int INF = 1e9;
const ll MOD = 1e9 + 7;

int main() {
    int n,k; cin >> n >> k;
    vector<int> a(n);
    rep(i,n) cin >> a[i];
    rep(i,n) a[i]--;

    vector<int> cum(n + 1);
    rep(i,n) cum[i + 1] = (cum[i] + a[i])%k;

    map<int,int> mp;
    mp[0] = 0;
    ll ans = 0;
    queue<int> q;
    rep(i,n + 1) {
        ans += mp[cum[i]];
        mp[cum[i]] ++;
        q.push(cum[i]);
        if (q.size() == k) {
            mp[q.front()] --;
            q.pop();
        }
    }
    cout << ans << endl;
    return 0;
}