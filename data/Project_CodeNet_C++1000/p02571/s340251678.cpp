/*input
cabacc
abc
*/

#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;

int main() {
    string s, t;
    cin >> s >> t;
    int sl = s.size(), tl = t.size();
    int match = 0;
    rep(i, sl-tl+1) {
        int tmp = 0;
        rep(j, tl) {
            tmp += s[i+j] == t[j];
        }
        match = max(match, tmp);
    }
    cout << tl-match << endl;
}