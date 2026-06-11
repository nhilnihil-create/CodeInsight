#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int N;
    cin >> N;
    unordered_map<string, int> mp;
    ll ans = 0;
    for (int i = 0; i < N; ++i) {
        string s;
        cin >> s;
        sort(s.begin(), s.end());
        ans += mp[s];
        mp[s]++;
    }

    cout << ans << endl;

    return 0;
}