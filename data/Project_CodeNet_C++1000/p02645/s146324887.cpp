#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
    string s;
    cin >> s;
    
    string ans = "";
    rep(i, 3) {
        ans += s[i];
    }

    cout << ans << endl;
    
    return 0;
}