#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define sz(x) int(x.size())
using namespace std;
typedef long long ll;
typedef pair<int, int> P;

const ll INF = 1LL << 60;

ll N, K;
vector<ll> A;

int main() {
    cin >> N >> K;
    A.resize(N);
    rep(i, N) {
        cin >> A[i];
        A[i]--;
    }

    vector<ll> sum(N + 1);
    sum[0] = 0;

    rep(i, N) {
        sum[i + 1] = (sum[i] + A[i]) % K;
    }

    // 長さがKであること
    queue<ll> que;
    map<ll, ll> mp;
    ll ans = 0;
    rep(i, N + 1) {
        ans += mp[sum[i]];
        mp[sum[i]]++;
        que.push(sum[i]);

        while (que.size() >= K) {
            mp[que.front()]--;
            que.pop();
        }
    }
    cout << ans << endl;
}