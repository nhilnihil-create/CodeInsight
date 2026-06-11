#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define sz(x) int(x.size())
#define show(x) {for(auto i: x){cout << i << " ";} cout << endl;}
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
    // dp, ApplePen
    int N, K;
    cin >> N >> K;
    vector<int> A(N);
    rep(i, N) {
        cin >> A[i];
        --A[i];
    }
    ll ans = 0;
    ll temp = 0;
    map<int, int> mp;
    vector<int> cum(N+1);
    queue<int> que;
    rep(i, N) cum[i+1] = (cum[i] + A[i]) % K;
    rep(i, N+1) {
        ans += mp[cum[i]];
        mp[cum[i]]++;
        que.push(cum[i]);
        if (sz(que) == K) {
            mp[que.front()]--;
            que.pop();
        }
    }
    cout << ans << '\n';
    return 0;
}