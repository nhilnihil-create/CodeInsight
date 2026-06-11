#include<iostream>
#include<algorithm>
#include<functional>
#include<cmath>
#include<string>
#include<vector>
#include<stack>
#include<queue>
#include<map>
#include<set>
#include<deque>
using namespace std;
#define ll long long
const int mod = 1000000007;
const ll INF = 1000000000000000000;

int dp[100010][20];
int main()
{
	string S;
	cin >> S;
	dp[0][0] = 1;
	int power = 1;
	int i = 0;
	dp[0][0] = 1;
	for (int k = S.size() -  1; k >= 0; k--,i++) {
		if (S[k] == '?') {
			for (int l = 0; l <= 9; l++) {
				int num = l * power % 13;
				for (int j = 0; j < 13; j++) {
					dp[i + 1][j] += dp[i][(j - num + 13) % 13];
					dp[i + 1][j] %= mod;
				}
			}
		}
		else {
			int num = (S[k] - '0') * power % 13;
			for (int j = 0; j < 13; j++) {
				dp[i + 1][j] += dp[i][(j - num + 13) % 13];
				dp[i + 1][j] %= mod;
			}
		}
		power = power * 10 % 13;
	}
	cout << dp[S.size()][5] << endl;
}
