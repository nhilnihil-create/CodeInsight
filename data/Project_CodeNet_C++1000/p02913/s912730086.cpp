#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define rep(i,n) for (int i = 0; i < (n); i++)
#define sz(x) int(x.size())
const ll mod = 1000000007;
const ll INF = 10010010010010010;

int main() {
    int n; cin >> n;
    string s; cin >> s;
    int ans = 0;
    for (int i = 1; i < n; i++) {
        int ansi = 0, cnt = 0;
        for (int j = 0; (i+j < n); j++) {
            if (s[j] == s[i+j]) cnt++;
            else {
                ansi = max(ansi,cnt);
                cnt = 0;
            }
            //printf("i = %d j = %d ansi = %d cnt = %d ans = %d\n",i,j,ansi,cnt,ans);
        }
        ansi = max(ansi,cnt);
        ansi = min(ansi,i);
        ans = max(ans,ansi);
    }
    cout << ans << endl;
    return 0;
}
