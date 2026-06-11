#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i=0; i<(n); ++i)
#define y_n(ans) cout<<(ans?"Yes":"No")<<endl;

int main() {
    string s;
    cin >> s;
    int n = s.size() + 1;
    vector<int> l(n), r(n);
    for (int i=1; i<n; ++i) {
        if (s[i-1] == '<') l[i] = l[i-1] + 1;
    }
    for (int i=n-2; i>=0; --i) {
        if (s[i] == '>') r[i] = r[i+1] + 1;
    }
    long long ans = 0;
    rep(i, n) {
        ans += max(l[i], r[i]);
    }
    cout << ans << endl;
}