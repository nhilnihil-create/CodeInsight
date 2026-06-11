#include <bits/stdc++.h>
using namespace std;

//const long double PIL = 3.141592653589793238462643383279502884L;
//const double PI = 3.14159265358979323846;

#define sz(a) int((a).size())
#define all(c) (c).begin(), (c).end()
#define debug(v) {for (auto z : v) {cerr << z << ' ';} cerr << endl;}

using ll = long long;
using ii = pair<int,int>;
using vi = vector<int>;
using vll = vector<long long>;
using vii = vector<pair<int,int>>;

const int N = 1e6 + 5;
const ll INF = 1e18;
char s[N];
ll dp[N][2];

void min_self(ll &a, ll b) {
	a = min(a, b);
}

int main() {
	//~ ios::sync_with_stdio(0);
	//~ cin.tie(0);
	//~ cout.tie(0);
	scanf("%s", s+1);
	s[0] = '0';
	int n = strlen(s);

	for (int i = 0; i <= n; i++)
		for (int j = 0; j < 2; j++)
			dp[i][j] = INF;
	dp[0][0] = 0;

	for (int i = 0; i < n; i++) {
		int d = s[i] - '0';
		min_self(dp[i+1][0], dp[i][0] + d);
		min_self(dp[i+1][1], dp[i][0] + d + 1);
		min_self(dp[i+1][0], dp[i][1] + 10 - d);
		min_self(dp[i+1][1], dp[i][1] + 9 - d);
	}

	printf("%lld\n", dp[n][0]);
}
