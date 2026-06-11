#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int n;
void dfs(string s, char mx) {
    if (s.length() == n) {
        cout << s << endl;
    } else {
        for (char c = 'a'; c <= mx; c++) {
            dfs(s + c, ((c == mx) ? mx+1 : mx));
        }
    }


}

void solve() {
    cin >> n;
    dfs("", 'a');
}

int main() {
    solve();
    return 0;
}

