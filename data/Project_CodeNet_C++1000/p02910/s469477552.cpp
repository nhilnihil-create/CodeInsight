#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define rep(i,n) for (int i = 0; i < (n); i++)
#define sz(x) int(x.size())
const ll mod = 1000000007;
const ll INF = 10010010010010010;

int main() {
    string s; cin >> s;
    int n = sz(s);
    int ans = 1;
    rep(i,n) {
        if (i%2 && s[i] == 'R') ans = 0;
        if (i%2 == 0 && s[i] == 'L') ans = 0;
    }
    if (ans) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}
