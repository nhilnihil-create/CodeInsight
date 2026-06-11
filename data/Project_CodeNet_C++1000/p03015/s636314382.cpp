#include <bits/stdc++.h>
using namespace std;
#define int long long
typedef pair<int,int> pi;
#define f first
#define s second
#define FAST ios_base::sync_with_stdio(0); cin.tie(0);

string L;
int dp[2][2]; //i'th index, whether or not it's equal L
const int mod = 1e9+7;

void add(int &a, int b) {
	a = b;
	a %= mod;
}

int32_t main() {
	cin >> L;
	int pos;
	dp[1][1] = 1;
	for (int i =0;i<L.length();i++) {
		pos = i%2;
		if (L[i] == '1') {
			add(dp[pos][0],dp[!pos][0] * 3 + dp[!pos][1]); //3 options or 0 0
			add(dp[pos][1],dp[!pos][1]*2); //1 0 or 0 1
		} else {
			add(dp[pos][0],dp[!pos][0]*3); //3 options
			add(dp[pos][1],dp[!pos][1]); //No options.
		}
	}
	cout << (dp[pos][0] +dp[pos][1]) % mod;
}
