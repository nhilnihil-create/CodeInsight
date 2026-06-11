#include <bits/stdc++.h>
using ll = long long;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define ALL(x) x.begin(),x.end()
using namespace std;


int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    string s,t;
    cin >> s >> t;
    int ans=0;
    rep (i, 3) if (s[i]==t[i]) ans++;
    cout << ans << endl;
    return 0;
}