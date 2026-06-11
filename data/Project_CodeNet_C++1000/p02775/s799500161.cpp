#include <bits/stdc++.h>
#define ll long long int
#define ld long double
#define f first+
#define s second
#define pb push_back
#define eb emplace_back
#define mk make_pair
#define mt make_tuple
#define MOD 1000000007
#define fo(i,a,b) for(i=a;i<b;i++)
#define foe(i,a,b) for(i=a;i<=b;i++)
#define all(x) x.begin(), x.end()
#define vi vector<int>
#define vl vector <long long int>
#define pii pair <int,int>
#define pll pair <long long int, long long int>
#define vpii vector< pair<int,int> >
#define vpll vector < pair <long long int,long long int> >
#define boost ios::sync_with_stdio(false); cin.tie(0)
using namespace std;
const int inf = 1e9 + 5;
const ll inf64 = 1e18 + 5;

int main()
{
	boost;
	string s;
	cin >> s;
	int n = s.size();
	int dp[n + 1][2];
	for(int i = 0; i <= n; i++) {
		for(int j = 0; j < 2; j++)
		dp[i][j] = inf;
	}
	dp[0][0] = 0, dp[0][1] = 1;
	for(int i = 1; i <= n; i++) {
		int x = s[i - 1] - '0';
		dp[i][0] = min(dp[i - 1][0] + x, dp[i - 1][1] + 10 - x);
		dp[i][1] = min(dp[i - 1][0] + x + 1, dp[i - 1][1] + 10 - x - 1);
	}
	cout << dp[n][0];
}
