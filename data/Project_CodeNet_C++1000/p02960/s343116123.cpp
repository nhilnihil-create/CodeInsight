#include <bits/stdc++.h>
#define all(X) (X).begin(),(X).end()
#define rall(X) (X).rbegin(),(X).rend()
#define pub push_back
#define puf push_front
#define pob pop_back
#define pof pop_front
#define ff first
#define ss second
#define P 1000000007
#define in(x, a, b) (a <= x && x < b)

using namespace std;
using ll = long long;
typedef pair<int, int> ii;
typedef vector<ii> vii; 
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vii> vvii;
const ll inf = 1000000001, INF = (ll)1e18 + 1;

int power(int a, int b) {
	int result = 1;
	while(b) {
		if(b % 2) result = (result * a) % 13;
		a = (a * a) % 13;
		b /= 2;
	}
	
	return result;
}

int divide13(int a, int b) {
	return a * power(b, 11) % 13;
}

void solve() {
	string s;
	cin >> s;
	
	int n = s.length();
	vvi dp(n + 1, vi(13, 0));
	dp[0][0] = 1;
	
	int pw = 1;
	for(int i = 0; i < n; i++) pw = (pw * 10) % 13;
	
	for(int i = 0; i < n; i++) {
		pw = divide13(pw, 10);
		if(s[i] == '?') {
			for(int j = 0; j < 13; j++) {
				for(int k = 0; k < 10; k++) {
					(dp[i + 1][(j + (k) * pw) % 13] += dp[i][j]) %= P;
				}
			}
		} else {
			for(int j = 0; j < 13; j++) {
				(dp[i + 1][(j + (s[i] - '0') * pw) % 13] += dp[i][j]) %= P;
			}
		}
	}
	
	cout << dp[n][5] << endl;
}

int main() {
	ios_base::sync_with_stdio(false);
	solve();
    return 0;
}