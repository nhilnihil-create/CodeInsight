#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < n; i++)
typedef long long ll;
typedef pair<int, int> PI;
typedef pair<ll, ll> PL;
using graph = vector<vector<int>>;

const double pi = 3.14159265358979323846;
const ll mod = 1000000007;

int main() {
	cin.tie(0);
   	ios::sync_with_stdio(false);
    int n, k; cin >> n >> k;
    ll dp[3000][3000];
    dp[0][0] = 1; dp[1][0] = 1; dp[1][1] = 1;
    for(int i = 2; i <= 2500; i++){
        dp[i][0] = 1; dp[i][i] = 1;
        for(int j = 1; j < i; j++){
            dp[i][j] = dp[i-1][j-1] + dp[i-1][j];
            dp[i][j] %= mod;
        }
    }
    ll ans;
    for(int i = 1; i <= k; i++){
        ans = dp[n-k+1][i] * dp[k-1][i-1] % mod;
        cout << ans << endl;
    }
} 