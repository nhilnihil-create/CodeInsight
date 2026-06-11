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
    vector<int> cum(N);
    mp[0] = 1;
    rep(i, N) {
        if (i == K-1) mp[0]--;
        if (i >= K) mp[cum[i-K]]--;
        temp += A[i];
        temp %= K;
        cum[i] = temp;
        ans += mp[temp]++;
    }
    cout << ans << '\n';
    return 0;
}