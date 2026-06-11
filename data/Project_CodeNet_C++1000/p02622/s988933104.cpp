#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
using pii = pair<int, int>;
using vi = vector<int>;
using vii = vector<vi>;
using ll = long long;

int main() {
    string s, a;
    cin >> s >> a;
    int ans = 0;

    int n = s.size();
    rep(i, n) {
        if (s[i] != a[i]) ans++;
    }
    cout << ans << endl;
    return 0;
}