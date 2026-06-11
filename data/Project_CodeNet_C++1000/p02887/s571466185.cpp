#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define rep(i,n) for (int i = 0; i < (n); i++)
#define all(v) (v).begin(), (v).end()
#define sz(x) int(x.size())
const ll mod = 1000000007;
int INF = 1001001001;

int main() {
    int n; cin >> n;
    string s; cin >> s;
    int ans = 1;
    rep(i,n-1) {
        if (s[i] != s[i+1]) ans++;
    }
    cout << ans << endl;
    return 0;
}
