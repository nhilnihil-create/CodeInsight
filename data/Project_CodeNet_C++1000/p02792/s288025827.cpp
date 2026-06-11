#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define irep(i, n) for (int i = (n); i >= 0; i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;
const int INF = 1 << 30;

int cnt[10][10];
int main() {
    int n;
    cin >> n;
    
    for (int a = 1; a <= n; a++)
    {
        string s = to_string(a);
        cnt[s[0]-'0'][s[s.size()-1]-'0']++;
    }
    ll ans = 0;
    for (int i=1; i<10;i++) {
        for (int j=1; j<10; j++) {
            ans += cnt[i][j] * cnt[j][i];
        }
    }
    cout << ans << endl;
    return 0;
}
