#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

const int mod = 2019;

int main() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    ll r = 0, g = 0, b = 0;
    rep(i,n) {
        if (s[i] == 'R') r++;
        if (s[i] == 'G') g++;
        if (s[i] == 'B') b++;
    }
    ll ans = r*g*b;
    for (int j = 1; j <= n-2; j++) {
        for (int i = 0; i < j; i++) {
            int k = 2*j-i;
            if (k > n-1) continue;
            if (s[i] == s[j]) continue;
            if (s[j] == s[k]) continue;
            if (s[k] == s[i]) continue;
            ans--;
        }
    }
    cout << ans << endl;
    return 0;
}