#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
#define INF (1<<29)
int dp[10000][10000];
int main()
{
	fill(dp[0], dp[1000], INF);
	string s1, s2; cin >> s1 >> s2;
	int s1sz = s1.size()+1, s2sz = s2.size()+1;
	for (int i = 0; i < s1sz; ++i) {
		dp[i][0] = i;
	}
	for (int j = 0; j < s2sz; ++j) {
		dp[0][j] = j;
	}
	for (int i = 1; i < s1sz; ++i) {
		for (int j = 1; j < s2sz; ++j) {
			dp[i][j] = min(dp[i - 1][j - 1] + (s1[i - 1] != s2[j - 1]), min(dp[i - 1][j] + 1, dp[i][j - 1] + 1));
		}
	}
	cout << dp[s1sz-1][s2sz-1] << endl;
}