#include <bits/stdc++.h>
using namespace std;
 
#define forn(i,n) for(int i=0;i<(int)(n);i++)
#define si(c) ((int)(c).size())
#define forsn(i,s,n) for(int i = (int)(s); i<((int)n); i++)
#define dforsn(i,s,n) for(int i = (int)(n)-1; i>=((int)s); i--)
#define all(c) (c).begin(), (c).end()
#define D(a) cerr << #a << "=" << a << endl;
#define pb push_back
#define eb emplace_back
#define mp make_pair
 
typedef long long int ll;
typedef vector<int> vi;
typedef pair<int,int> pii;
 
const int N = 2e5 + 10;
int dp[N][2];

int main() {
    string s; cin >> s;
    int n = si(s);

    for (int i = n-1; i >= 0; i--) {
        for (int one = 0; one < 2; one++) {
            dp[i][one] = 0;
            if (i+2 <= n) dp[i][one] = max(dp[i][one], 1 + dp[i+2][0]);
            if (!one || i == 0 || s[i-1] != s[i]) dp[i][one] = max(dp[i][one], 1 + dp[i+1][1]);
        }
    }
    cout << dp[0][0] << '\n';

    return 0;
}
