#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
const int infty = static_cast <int> (pow(256, sizeof(int)) / 2 - 1);

int knapsack(int n, int w, vector<int> &vv, vector<int> &vw)
{
	vector<vector<int>> vvc;
	vvc = vector<vector<int>>(vv.size(),vector<int>(w+1,0));

	for(int i = 0; i <= w; ++i)
	{
		vvc[0][i] = 0;
	}

	for(int i = 0; i <= n; ++i)
	{
		vvc[i][0] = 0;
	}

	for(int i = 1; i <= n; ++i)
	{
		for(int j = 1; j <= w; ++j)
		{ 
			if(vw[i] <= j)
			{
				if((vv[i] + vvc[i-1][j-vw[i]]) > vvc[i-1][j])
					vvc[i][j] = vv[i] + vvc[i - 1][j - vw[i]];
				else
					vvc[i][j] = vvc[i - 1][j];
			}
			else
				vvc[i][j] = vvc[i - 1][j];
		}
	}
	return vvc[n][w];
}

int main()
{
	cin.tie(0);
	ios::sync_with_stdio(false);

	int n, w;
	cin >> n >> w;
	cin.ignore();

	int a, b;
	vector<int> vv,vw;

	vv.push_back(0);
	vw.push_back(0);

	for (int i = 0; i < n; ++i)
	{
		cin >> a >> b;
		vv.push_back(a);
		vw.push_back(b);
	}

	cout << knapsack(n,w,vv,vw) << endl;

	return 0;
}