#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define rep(i,n) for (int i = 0; i < (n); i++)
#define sz(x) int(x.size())
const ll mod = 1000000007;
const ll INF = 10010010010010010;


int main() {
    string s,t; cin >> s >> t;
    int ans = 0;
    rep(i,3) {
        if (s[i] == t[i]) {
            ans++;
        }
    }
    cout << ans << endl;
    return 0;
}
