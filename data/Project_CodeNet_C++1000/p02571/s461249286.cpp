#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);++i)
typedef long long int ll;

int main() {
        string s, t;
        cin >> s >> t;
        int ans = t.size();
        for (int start = 0; start <= s.size() - t.size(); start++) {
                int diff = 0;
                rep(i,t.size()) {
                        if (t[i] != s[start+i]) {
                                diff++;
                        }
                }
                ans = min(ans, diff);
        }
        cout << ans << endl;
}