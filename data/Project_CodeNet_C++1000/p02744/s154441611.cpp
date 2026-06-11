#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
typedef long long ll;

int N;

void dfs(string s, char mx) {
    if (s.length() == N) cout << s << endl;
    else {
        for (char c = 'a'; c < mx; c++) {
            dfs(s+c, mx);
        }
        dfs(s+mx, (char)(mx+1));
    }
}

int main() {
    cin >> N;
    dfs("", 'a');
}
