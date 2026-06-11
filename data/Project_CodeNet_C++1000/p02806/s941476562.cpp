#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define all(aaa) aaa.begin(), aaa.end()

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    vector<pair<string, int>> v;

    ll ans = 0;

    for (int i = 0; i < n; i++) {
        string s;
        int t;
        cin >> s >> t;
        v.emplace_back(s, t);
        ans += t;
    }

    string x;
    cin >> x;

    for (const auto &p : v) {
        ans -= p.second;
        if (p.first == x)
            break;
    }

    cout << ans;

    return 0;
}