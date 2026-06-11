#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define all(v) (v).begin(),(v).end()
using ll = long long;
using P = pair<int, int>;
using Graph = vector<vector<int>>;

int main() {
    string S, T;
    cin >> S >> T;
    int ans = T.size();
    rep(start, S.size() - T.size() + 1) {
        int diff = 0;
        rep(i, T.size()) {
            if (S[start + i] != T[i]) diff++;
        }
        ans = min(ans, diff);
    }
    cout << ans << endl;
    return 0;
}