#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, a, b) for (register int i = a; i <= b; i++)

int n, a[200010];
int cnt[1000010], ans;
inline void solve(int T) {
    cin >> n;
    rep(i, 1, n) cin >> a[i];
    sort(a + 1, a + n + 1);
    rep(i, 1, n) {
        if(!cnt[a[i]]) {
            if(a[i] != a[i + 1]) ans++;
            while(a[i] == a[i + 1]) i++;
            for(int j = 2; j * a[i] <= 1000000; j++) cnt[j * a[i]] = 1;
        }
    }
    cout << ans << endl;
}   
int main()
{
//     ios_base::sync_with_stdio(0);
//     cin.tie(0);
//     cout.tie(0);
 
    // freopen("in.txt", "r", stdin);
    // freopen("out2.txt", "w", stdout);
 
    int T = 1;
    // cin >> T;
    rep(i, 1, T) solve(i);
}