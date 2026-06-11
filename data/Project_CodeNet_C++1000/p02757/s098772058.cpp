#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define debug(x) cerr << "[(" << __LINE__ << ") " << (#x) << "]: " << x << endl;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, p;
    string s;
    cin >> n >> p >> s;

    vector<int> dp(p);
    dp[0]++;

    ll ans = 0;
    ll duh = 1, cur = 0;

    if (p == 2 || p == 5) {
        for (int i=1; i<n+1; i++) {
            if (p == 2 && (s[i-1]-'0') % 2 == 0) ans += i;
            if (p == 5 && (s[i-1]-'0') % 5 == 0) ans += i;
        }
    } else { 
        for (auto c=s.rbegin(); c!=s.rend(); c++) {
            cur += (*c - '0') * duh;
            cur %= p;

            duh *= 10;
            duh %= p;

            ans += dp[cur];
            dp[cur]++;
        }
    }
    
    cout << ans << "\n";
}
