#include <bits/stdc++.h>
using namespace std;
using lint = long long;
using P = pair<int, int>;
using vec = vector<lint>;
using mat = vector<vector<int>>;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define all(v) v.begin(), v.end()
#define endl "\n"

constexpr int MOD = 1000000007;
const int INF = 1 << 30;

int main() {
    int n, k;
    cin >> n >> k;
    vec a(n);
    rep(i, n) cin >> a[i];

    vec s(n+1);
    rep(i, n) s[i+1] = (s[i] + a[i]);

    vec t(n+1);
    rep(i, n+1) t[i] = (s[i] - i) % k;
    rep(i, n+1) t[i] = ((t[i] % k) + k) % k;

    lint res = 0;
    map<int, int> mp;
    queue<int> que;

    rep(i, n+1) {
        res += mp[t[i]];
        mp[t[i]]++;

        que.push(t[i]);
        if (que.size() >= k) {
            mp[que.front()]--;
            que.pop();
        }
    }

    cout << res << endl;
    return 0;
}