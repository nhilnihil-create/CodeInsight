#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define rep(i,n) for (int i = 0; i < (n); i++)
#define sz(x) int(x.size())
const ll mod = 1000000007;
const ll INF = 10010010010010010;

int main() {
    int n,k; cin >> n >> k;
    string s; cin >> s;
    int cnt = 0;
    rep(i,n) {
        if (s[i] == 'L') {
            if (i > 0 && s[i-1] == 'L') cnt++;
        } else {
            if (i < n-1 && s[i+1] == 'R') cnt++;
        }
    }
    int cnt2 = n-1-cnt;
    int ans = cnt + min(2*k,cnt2);
    cout << ans << endl;
    return 0;
}
