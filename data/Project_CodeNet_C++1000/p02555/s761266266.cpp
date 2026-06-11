#include <iostream>
#include <algorithm>
#include <iomanip>
#include <string>
#include <vector>
#include <math.h>
#include <queue>
#include <deque>
#include <stack>
#include <map>
#include <set>
#define PI 3.14159265359
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pai;
typedef pair<ll, ll> pal;
const int MOD = 1e9+7;
const ll LLINF = 1e18;

int dp[2001];
int main(){
	int s;
	cin >> s;
	dp[3] = 1;
	for (int i = 4; i <= s; i++){
		dp[i] = dp[i-1] + dp[i-3];
		dp[i] %= MOD;
	}
	cout << dp[s] << endl;
	return 0;
}

