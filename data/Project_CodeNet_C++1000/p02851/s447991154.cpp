#include<bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> A(n);
    rep(i, n) cin >> A[i];
    vector<int> S(n+1);
    S[0] = 0;
    rep(i, n) S[i+1] = (S[i] + A[i] - 1) % k;
    map<int, int> mp;
    ll ans = 0;
    for (int i = 0; i <= n; ++i) {
        ans += mp[S[i]];
        mp[S[i]]++;
        if (i >= k-1) mp[S[i-(k-1)]]--; 
    }
    cout << ans << endl;
    return 0;
}