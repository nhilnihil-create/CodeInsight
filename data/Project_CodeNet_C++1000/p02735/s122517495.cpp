#include<bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = (a); i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define sz(x) ((int)(x).size())
#define endl '\n'

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;

const ll mod=1000000007;
//head

int main()
{
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int r, c;
    cin >> r >> c;

    vector<string> g(r);
    for(int i = 0; i < r; i++) cin >> g[i];

    vector<vector<int>> dp(r,vi(c,1 << 30));
    
    dp[0][0] = (g[0][0] == '#');

    for(int i = 0; i < r; i++) {
        for(int j = 0; j < c; j++) {
            if(i > 0) dp[i][j] = min(dp[i][j], dp[i-1][j] + (g[i-1][j] == '.' && g[i][j] == '#'));
            if(j > 0) dp[i][j] = min(dp[i][j], dp[i][j-1] + (g[i][j-1] == '.' && g[i][j] == '#'));
        }
    }
    if(dp[r-1][c-1] == 1 << 30) {
        cout << 0 << endl;
    } else {
        cout << dp[r-1][c-1] << endl;
    }
    
    return 0;
}
