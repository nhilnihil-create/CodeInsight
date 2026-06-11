/* BABA JAGAAAAAA  */  

#include<bits/stdc++.h>
#define pb push_back
#define un unordered_map
#define us unordered_set
#define ll long long
#define PI 3.1415926535897932384626
#define fast ios:: sync_with_stdio(false);cin.tie(NULL)
#define l long 
using namespace std;
const int  mod= 1e9+7;
const int inf=1e9+3;
int dp[2020];

int main()
{
	int n;
	scanf("%d", &n);
	dp[1] = 0;
	dp[2] = 0;
	dp[3] = 1;
	for (int i = 4; i <= n; i++)
	{
		dp[i] = (dp[i - 1] + dp[i - 3]) % mod;
	}
	printf("%d", dp[n]);
}
  