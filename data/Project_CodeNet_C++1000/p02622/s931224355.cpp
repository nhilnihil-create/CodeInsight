#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);++i)
typedef long long int ll;

int main() {
        string s, t; cin >> s >> t;
        int ans = 0;
        rep(i,s.length()) {
                if (s[i]!=t[i]) {
                        ans++;
                }
        }
        cout << ans << endl;
}