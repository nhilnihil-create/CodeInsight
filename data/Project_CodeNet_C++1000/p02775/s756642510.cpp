#include<algorithm>
#include<cmath>
#include<cstdio>
#include<functional>
#include<iomanip>
#include<iostream>
#include<map>
#include<numeric>
#include<queue>
#include<set>
#include<string>
#include<utility>
#include<vector>

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const ll MOD = 1000000007;
#define rep(i,n) for(int i=0;i<n;i++)
#define repl(i,s,e) for(int i=s;i<e;i++)
#define reple(i,s,e) for(int i=s;i<=e;i++)
#define revrep(i,n) for(int i=n-1;i>=0;i--)
#define all(x) (x).begin(),(x).end()

int main()
{	
	string N;
	cin >> N;

	//N円払うためには紙幣をN円以上支払う必要があるが、
	//最小枚数を意識すると、
	//1.各桁の紙幣をぴったり払う
	//2.どこかの桁を1.より1枚多くはらう
	//・この場合、その桁より小さい桁は任意枚数でよい。
	//・最大桁より大きい桁でもよい（最小枚数の条件から、最大+1桁のみ考慮すればよい）。
	//
	//よって、最大+1桁からDPで以下を計算すればよい。
	//1.その桁をぴったり払う
	//2.その桁以上の桁で1枚多く払う

	//dp[0][i] := i桁目をちょうどの枚数で払う場合の紙幣の合計枚数
	//dp[0][i] := i桁目を1枚余分に払う場合の紙幣の合計枚数
	vector<vector<ll>> dp(2, vector<ll>(N.size() + 1, 0));


	//最大+1桁は「0」とみなす。
	dp[1][0] = 1;

	rep(i, N.size())
	{
		ll d = (ll)(N[i] - '0');

		dp[0][i + 1] = min(dp[0][i] + d, dp[1][i] + 10 - d);
		dp[1][i + 1] = min(dp[0][i] + d + 1, dp[1][i] + 9 - d);
	}

	cout << dp[0][N.size()] << endl;

	return 0;
}