#include <cstdio>
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <map>
#include <set>
#include <queue>
#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <typeinfo>
#include <numeric>
#include <functional>
#include <unordered_map>
#include <bitset>
#include <stack>


using namespace std;
using ll = long long;
using ull = unsigned long long;

const ll INF = 1e16;
const ll MOD = 1e9 + 7;

#define REP(i, n) for(ll i = 0; i < n; i++)















int main() {
	char s[1000002] = "0";
	scanf("%s", &s[1]);
	int dp[2] = { 0, (int)1e9 };
	for(int i = 0; s[i] != '\0'; i++){
		int num = s[i] - '0', tmp[2] = { (int)1e9, (int)1e9 };
		tmp[0] = min(tmp[0], dp[0] + num);
		tmp[1] = min(tmp[1], dp[0] + num + 1);
		tmp[0] = min(tmp[0], dp[1] + 10 - num);
		tmp[1] = min(tmp[1], dp[1] + 9 - num);
		dp[0] = tmp[0];
		dp[1] = tmp[1];
	}
	printf("%d\n", dp[0]);
}