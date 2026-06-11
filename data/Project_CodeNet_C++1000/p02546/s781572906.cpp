#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

void solve() {
    string s;
    cin >> s;

    if (s[s.length()-1] == 's') {
        cout << s << "es" << endl;
    } else {
        cout << s << "s" << endl;
    }
}

int main() {
    solve();
    return 0;
}
