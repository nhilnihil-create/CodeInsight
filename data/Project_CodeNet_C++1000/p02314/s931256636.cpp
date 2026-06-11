#include <iostream>
#include <vector>
using namespace std;


int table[25][50005] = {};

int main()
{
	int n;
	int m;
	int coin[25];
	
	
	cin >> n >> m;
	
	
	for(int i = 0; i < m; ++i)
	{
		cin >> coin[i];
	}
	
	
	for(int now = 0; now < m; ++now)
	{
		for(int sum = 0; sum < n; ++sum)
		{
			if(sum - coin[now] < 0 && now - 1 < 0) table[now][sum] = 1;
			else if(sum + 1 - coin[now] < 0) table[now][sum] = table[now - 1][sum];
			else if(now - 1 < 0) table[now][sum] = table[now][sum - coin[now]] + 1;
			else table[now][sum] = min(table[now][sum - coin[now]] + 1, table[now - 1][sum]);
		}
	}
	
	cout << table[m - 1][n - 1] << endl;
	
	return 0;
}