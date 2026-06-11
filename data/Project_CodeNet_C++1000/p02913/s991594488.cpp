#pragma GCC optimize ('O3')
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll,ll> pll;
typedef long double ld;
#define mp make_pair
#define f first
#define s second
#define pb push_back

const int N = 5e3 + 5;
const int M = 1e5 + 5;
const ll OO = 1e18;
const int mod = 1e9 + 7;


int n,ans,dp[N][N];
string s;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> s;

    for (int i = n-1; ~i; --i) {
        for (int j = n-1; ~j; --j) {
            if(s[i]==s[j]) ans = max(ans, dp[i][j] = min(dp[i+1][j+1]+1, j-i));
        }
    }

    cout << ans << '\n';

    return 0;
}