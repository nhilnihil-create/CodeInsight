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
const int MOD = 1e9+7;
const int MOOD = 998244353;
#define PI 3.14159265359
typedef long long ll;
using namespace std;

ll dp[3000][3001];


int main(){
	int n, s;
	cin >> n >> s;
	vector<int> a(n);
	for (int i = 0; i < n; i++) cin >> a[i];

	dp[0][0] = 2;	
	dp[0][a[0]] = 1;

	for (int i = 1; i < n; i++){
		for (int j = 0; j <= s; j++){
			if (dp[i-1][j] != 0){
				if (j + a[i] <= s){
					dp[i][j+a[i]] += dp[i-1][j];
					dp[i][j+a[i]] %= MOOD;
				}
				dp[i][j] += dp[i-1][j]*2;
				dp[i][j] %= MOOD;
			}
		}
	}
	cout << dp[n-1][s] << endl;
	return 0;
}