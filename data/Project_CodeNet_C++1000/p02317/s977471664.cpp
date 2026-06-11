#include <iostream>
#include <iomanip>
#include <sstream>
#include <stdio.h>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
#include <math.h>
#include <utility>
#include <string>
#include <ctype.h>
#include <cstring>
#include <cstdio>
#include <sstream>
#include <functional>

using namespace std;

#define FOR(i,k,n) for(int i = (k); i < (n); i++)
#define REP(i,n) FOR(i,0,n)
#define INF 1145141919
#define ll long long
//#define scanf scanf_s

int n,a[100005],dp[100005];

int main()
{
	cin >> n;
	REP(i, n) cin >> a[i];
	fill(dp, dp + 100005, INF);
	REP(i, n) *lower_bound(dp, dp + n, a[i]) = a[i];
	cout << lower_bound(dp, dp + n, INF) - dp << endl;
}