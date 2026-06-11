#include <iostream>
#include <algorithm>

using namespace std;

int N,W,v[100],w[100],dp[100][100000];

int maxval(int _d,int _w)
{
	if((_w > 0 && _d < N))
	{
		if(dp[_d][_w] != 0)
		{
			return dp[_d][_w];
		}
		else
		{
			int res1 = 0;
			if(w[_d] <= _w)
			{
				res1 = maxval(_d + 1,_w - w[_d]) + v[_d];
			}
			int res2 = maxval(_d + 1,_w);
			dp[_d][_w] = max(res1,res2);
			return max(res1,res2);
		}
	}
	else
		return 0;
}

int main(void)
{
	cin >> N >> W;
	for(int i = 0;i < N;i++)
	{
		cin >> v[i] >> w[i];
	}
	int result = maxval(0,W);
	cout << result << "\r\n";
	return 0;
}