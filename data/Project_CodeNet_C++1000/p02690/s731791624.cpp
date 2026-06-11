#include <bits/stdc++.h>
using namespace std;
#define int long long
const int M = 5e3 + 5;
int x, pw[2 * M];
 
int32_t main() 
{
	ios_base::sync_with_stdio(0);	cin.tie(0);	cout.tie(0);
	for(int i = -M; i < M; i++)
		pw[i + M] = pow(i, 5);
	cin >> x;
	for(int i = -M; i < M; i++)
	{
		int a = pw[i + M];
		for(int j = -M; j < M; j++)
		{
			int b = pw[j + M];
			if(a - b == x)
				return cout << i << " " << j, 0;
		}
	}
    	return 0;
}