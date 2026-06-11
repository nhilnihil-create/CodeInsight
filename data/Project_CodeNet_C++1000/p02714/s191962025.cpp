#include <bits/stdc++.h>
#define repl(i, l, r) for (ll i = l; i < r; i++)
#define rep(i, n) repl(i, 0, n)
using namespace std;
using ll = long long;
using ld = long double;
using P = pair<int, int>;

int main()
{
    ll n;
    string s;
    cin >> n;
    cin >> s;
    ll r = 0;
    ll g = 0;
    ll b = 0;
    rep(i, n) {
        if(s[i] == 'R') r++;
        else if(s[i] == 'G') g++;
        else b++; 
    }
    ll ans = r * g * b;
    rep(i, n) {
        for(int j = 0; i - j >= 0 && i + j < n; j++) {
            if(s[i - j] != s[i] && s[i] != s[i + j] && s[i - j] != s[i + j]) {
                ans--;
            }
        }
    }
    cout << ans << endl;
    return 0;
}
