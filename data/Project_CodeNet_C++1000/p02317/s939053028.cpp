#include <iostream>
#include <iomanip>
#include <algorithm>
#include <stack>
#include <queue>
#include <vector>
#include <map>
#include <bitset>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <climits>

#define MAX_N 100000
#define INF INT_MAX / 2

using namespace std;

int main() {
	int n;
	int a[MAX_N];
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	int dp[MAX_N];
	fill_n(dp, MAX_N, INF);
	dp[0] = a[0];
	int len = 1;
	for (int i = 1; i < n; i++)
		if (dp[len-1] < a[i])
			dp[len++] = a[i];
		else {
			int j = len-1;
			for (; j >= 0; j--)
				if (dp[j] < a[i])
					break;
			dp[j+1] = a[i];
		}
	cout << len << endl;
	return 0;
}