#include <iostream>
#include <sstream>
#include <stdio.h>
//#define _USE_MATH_DEFINES
#include <math.h>
#include <set>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <cmath>
#include <limits>
#include <bitset>
#include <stack>
#include <queue>
#include <ctype.h>

typedef long long int lli;
#define rep(i,s,N) for(int i=s;i<N;i++)
#define MOD 1000000007
#define more(a,b) (((a)>(b))?(a):(b))
#define less(a,b) (((a)<(b))?(a):(b))

using namespace std;


int main(void)
{
	string S; cin >> S;
	vector<vector<int>> dp(S.size() + 1, vector<int>(2, 0));
	dp[1][0] = 1; 
	rep(i, 2, S.size() + 1) {
		if (S[i - 1] != S[i - 2])dp[i][0] = dp[i - 1][0] + 1;
		if (i >= 3 && (S[i - 3] != S[i - 1] || S[i - 2] != S[i]))
			dp[i][1] = dp[i - 2][1] + 1;
		dp[i][0] = max(dp[i][0], dp[i - 1][1] + 1);
		dp[i][1] = max(dp[i][1], dp[i - 2][0] + 1);
	}

	cout << (max(dp[S.size()][0], dp[S.size()][1])) << endl;

	return 0;
}