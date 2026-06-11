#include <bits/stdc++.h>
#define all(X) (X).begin(),(X).end()
#define P 1000000007
#define CASET int ___T; scanf("%d", &___T); for(int cs=1;cs<=___T;cs++)

using namespace std;
using ll = long long;
typedef pair<int, int> ii;
typedef vector<ii> vii; 
typedef vector<int> vi;

void solve() {
	int h, n;
	cin >> h >> n;
	vi a(n), b(n);
	for(int i = 0; i < n; i++) cin >> a[i] >> b[i];
	
	int mx = 0;
	for(int i = 0; i < n; i++) mx = max(mx, a[i]);
	
	int dp[1000010];
	fill(dp, dp + 1000010, 1e9);
	dp[0] = 0;
	for(int j = 0; j + mx < 1000010; j++) {
		for(int i = 0; i < n; i++) {
			dp[j + a[i]] = min(dp[j + a[i]], dp[j] + b[i]);
		}
	}
	
	int mn = 1e9;
	for(int i = h; i < 1000001; i++) mn = min(mn, dp[i]);
	
	cout << mn << endl; 
}

int main(){
#define MULTITEST 0
#if MULTITEST   
 
    CASET {
        solve();
    }
    
#else

    solve();
    
#endif

    return 0;
}