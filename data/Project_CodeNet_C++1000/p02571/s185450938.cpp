#include <bits/stdc++.h>
#define ll long long
#define pb(x) push_back((x))
#define line() cerr << "DEBUG @" << __LINE__ << endl;
#define debug(x) \
    cerr << "DEBUG @" << __LINE__ << " -> " << #x << " = " << x << endl;
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    string s, t;
    cin >> s >> t;
    int n = s.size();
    int m = t.size();
    int best = 0;
    for (int i = 0; (i + m - 1) < n; i++) {
        int cur = 0;
        for (int j = i; j < i + m; j++) {
            cur += s[j] == t[j - i];
        }
        best = max(best, cur);
    }
    cout << (m - best) << endl;
}
