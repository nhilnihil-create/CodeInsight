#include <iostream>
#include <climits>

using namespace std;

#define LIM 1000001

long int n, tet[501] = {0}, dp[LIM] = {0}, dp_odd[LIM] = {0};

void solve()
{
	for(int j = 0; j < LIM; j++)
	{
		for(int i = 1; j+tet[i] < LIM; i++)
		{
			if( dp[j+tet[i]] > dp[j] + 1 )
				dp[j+tet[i]] = dp[j] + 1;
		}
	}

	for(int j = 0; j < LIM; j++)
	{
		for(int i = 1; j+tet[i] < LIM; i++)
		{
			if( dp_odd[j+tet[i]] > dp_odd[j] + 1 && tet[i] % 2 == 1)
				dp_odd[j+tet[i]] = dp_odd[j] + 1;
		}
	}

	return;
}

int main()
{
	for( int i = 1; i < 501; i++)
		tet[i] = i*(i+1)*(i+2)/6;

	for( int i = 1; i < LIM; i++)
	{
		dp[i] = INT_MAX;
		dp_odd[i] = INT_MAX;
	}

	solve();

	while( cin >> n, n)
	{
		cout << dp[n] << " ";
		cout << dp_odd[n] << endl;
	}

	return 0;
}