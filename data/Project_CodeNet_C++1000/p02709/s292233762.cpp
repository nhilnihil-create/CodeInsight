#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;
#define forr(i,a,n) for (int i = (a); i < (n); ++i)
#define rforr(i,a,n) for (int i = (a); i > (n); --i)
#define ALL(x) x.begin(),x.end()
#define LEN(X) ((int)(X).size())
#define CASET int _T; cin >> _T; forr(caset,0,_T)
#define int ll



signed main() {
    ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    //freopen("input.txt","r",stdin);
    int n; cin >> n;

    vector<pii> a(n); 
    forr(i,0,n) {
        int h; cin >> h;
        a[i] = make_pair(h, i+1);
    }
    sort(ALL(a));
    reverse(ALL(a));

    // dp[i][j] i to the left, j to the right
    vector<vector<int>> dp (n+1, vector<int> (n+1, 0));

    int hap = 0;
    forr(i,0,n+1) {
        forr(j,0,n+1) {
            if (i==0 && j==0) continue;
            if (i+j > n) break;
            if (j > 0) {
                dp[i][j] = max(dp[i][j], dp[i][j-1] + a[i+j-1].first*(n+1 - j - a[i+j-1].second));
            }
            if (i > 0) {
                dp[i][j] = max(dp[i][j], dp[i-1][j] + a[i+j-1].first*(a[i+j-1].second - i));
            }
            // cout << i << " " << j << " " << dp[i][j] << '\n';
            hap = max(hap, dp[i][j]);
        }
    }

    cout << hap << '\n';

}
