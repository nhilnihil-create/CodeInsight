#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, a, b) for (register int i = a; i <= b; i++)
 
int n;
char color[200010];
int id, tmp, ans;
int r[200010];
inline void solve(int T) {
    cin >> n;
    cin >> color + 1;
    id = tmp = ans = 0;
    rep(i, 1, n) if(color[i] == 'R') r[++id] = i;
    rep(i, 1, n) {
        if(i >= r[id]) break;
        if(color[i] == 'W') {
            ans++;
            id--;
        }
    }
    cout << ans << endl;
}   
int main()
{
    // ios_base::sync_with_stdio(0);
    // cin.tie(0);
    // cout.tie(0);
 
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
 
    int T = 1;
    // cin >> T;
    rep(i, 1, T) solve(i);
    // system("pause");
}