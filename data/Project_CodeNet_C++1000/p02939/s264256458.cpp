#include<iostream>
#include<iomanip>
#include<cstdio>
#include<algorithm>
#include<cassert>
#include<cmath>
#include<vector>
#include<map>
//#include<unordered_map>
//#include<unordered_set>
#include<set>
#include<string>
#include<queue>
#include<stack>
#include <cstring>
#include <functional>
using namespace std;
#define MOD 1000000007
#define MOD2 998244353
#define INF ((1<<30)-1)
#define LINF (1Int<<60)
#define EPS (1e-10)
typedef long long Int;
typedef pair<Int, Int> P; 
const int N = 200005;
//////////////////////////////
 
int n;
string s;
int dp[N];
 
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
 
	memset(dp, 0, sizeof dp);
 
	cin >> s;
	n = s.size();
	dp[1] = 1;
	if (s[0] == s[1])dp[2] = 1;
	else dp[2] = 2;
 
	for (int i = 3; i <= n; i++) {
		if (s[i - 1] != s[i - 2]) dp[i] = dp[i - 1] + 1;
		else dp[i] = dp[i - 3] + 2;
	}
 
	cout << dp[n] << endl;
 
	return 0;
}