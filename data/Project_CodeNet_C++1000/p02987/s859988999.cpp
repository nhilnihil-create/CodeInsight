#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define rep(i,n) for (int i = 0; i < (n); i++)
const ll mod = 1000000007;

int main() {
    string s;
    cin >> s;
    int ans = 0;
    if (s[0] == s[1] && s[2] == s[3]) ans++;
    if (s[0] == s[2] && s[1] == s[3]) ans++;
    if (s[0] == s[3] && s[1] == s[2]) ans++;
    if (ans && ans != 3) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}