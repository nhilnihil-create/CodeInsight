#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < n; i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

#include <bits/stdc++.h>
using namespace std;

// r -> P, s -> R, p -> S
int main() {
    int N, K, R, S, P;
    string T;
    cin >> N >> K >> R >> S >> P >> T;
    vector<string> s(K);
    rep(i, N) s[i % K] = s[i % K] + T[i];
    int ans = 0;
    rep(i, K) {
        char c = 'n';
        rep(j, s[i].size()) {
            if(s[i][j] != c) {
                if(s[i][j] == 'r') {
                    ans += P;
                } else if(s[i][j] == 's') {
                    ans += R;
                } else if(s[i][j] == 'p') {
                    ans += S;
                }
                c = s[i][j];
            } else {
                c = 'n';
            }
        }
    }
    cout << ans << endl;
}