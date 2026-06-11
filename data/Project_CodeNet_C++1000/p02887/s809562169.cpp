#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < n; i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

const long long mod = 1e9 + 7;

int main() {
    int n;
    string s;
    cin >> n >> s;
    string ans = "";
    ans += s[0];
    rep(i, n - 1) {
        if(s[i] == s[i + 1])
            continue;
        else {
            ans += s[i + 1];
        }
    }

    cout << ans.size() << endl;
    return 0;
}