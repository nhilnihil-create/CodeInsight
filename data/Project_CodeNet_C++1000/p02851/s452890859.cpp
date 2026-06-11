#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define sz(x) int(x.size())
using namespace std;
typedef long long ll;

const ll INF = 1e10;
ll N, K;
vector<ll> A;

int main() {
    cin >> N >> K;
    A.resize(N);
    rep(i, N) cin >> A[i];
    rep(i, N) A[i]--;

    vector<ll> s(N + 1);
    s[0] = 0;
    rep(i, N) s[i + 1] = (s[i] + A[i]) % K;

    map<ll, ll> mp;
    queue<ll> q;
    ll ans = 0;
    rep(j, N + 1) {
        ans += mp[s[j]];
        mp[s[j]]++;
        q.push(s[j]);
        while (q.size() >= K) {
            mp[q.front()]--;
            q.pop();
        }
    }
    cout << ans << endl;
}