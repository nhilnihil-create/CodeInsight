#include <bits/stdc++.h>
using namespace std;

#define all(v)  begin(v), end(v)
#define endl    '\n';
#define int     long long
#define pii     pair<int, int>
#define sz(x)   (int) x.size()

void test_case() {
    string s; cin >> s;
    int n = sz(s);

    vector<int> pos;
    for (int i = 0; i <= n-2; i++) {
        if (s[i] == 'R' && s[i+1] == 'L') 
            pos.push_back(i);
    }
    vector<int> cnt(n, 0);
    for (int i = 0; i < n; i++) {
        auto it = lower_bound(all(pos), i);
        if (s[i] == 'L') {
            it = upper_bound(all(pos), i);
            it--;
        }
        cnt[*it + (abs(i - *it) & 1)]++;
    }
    for (int& x : cnt)
        cout << x << ' ';
    cout << endl;
}

int32_t main() { 
    ios_base::sync_with_stdio(0); 
    cin.tie(0);

    int t = 1;
    // cin >> t;

    while (t--) { 
        test_case();
    }
    return 0;
}
