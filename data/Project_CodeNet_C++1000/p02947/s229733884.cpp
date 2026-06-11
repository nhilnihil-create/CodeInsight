#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main() {
    int n;
    string s[100000];
    cin >> n;
    for (int i = 0; i < n; i++) cin >> s[i];

    ll ans = 0;
    unordered_map<string, ll> um;
    for (int i = 0; i < n; i++) {
        sort(s[i].begin(), s[i].end());
        ans += um[s[i]];
        um[s[i]]++;
    }

    cout << ans << endl;
}
