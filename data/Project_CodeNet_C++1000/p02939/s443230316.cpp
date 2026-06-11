#include <cstdio>
#include <algorithm>  
#include <bitset>
#include <cassert>
#include <ctime>  
#include <cmath>  
#include <cstdlib>  
#include <cstring>  
#include <functional>  
#include <iostream>  
#include <deque>  
#include <stack>
#include <queue>  
#include <vector>  
#include <map>  
#include <set>  
#include <string>  
#include <unordered_map>  
#include <unordered_set>  
#pragma warning(disable:4996)

using namespace std;

#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
#define endl '\n'

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<double, int> pdi;

const int INF = 1e9;
const int MAXN = 3e5 + 5;
const int SZ = 1 << 19;

char A[MAXN];
int dp[MAXN][3];

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> A+1;
	int N = strlen(A+1);

	memset(dp, -1, sizeof(dp));

	dp[1][1] = 1, dp[2][2] = 1;
	if(A[1] != A[2]) dp[2][1] = 2;

	for(int i=3; i<=N; i++) {
		if(dp[i-1][1] != -1 && A[i-1] != A[i]) dp[i][1] = dp[i-1][1]+1;
		if(dp[i-1][2] != -1) dp[i][1] = max(dp[i][1], dp[i-1][2]+1);
		if(dp[i-2][1] != -1) dp[i][2] = dp[i-2][1]+1;
		if(dp[i-2][2] != -1 && !(A[i-3]==A[i-1] && A[i-2]==A[i])) dp[i][2] = max(dp[i][2], dp[i-2][2]+1);
	}
	cout << max(dp[N][1], dp[N][2]);
}
