#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <math.h>
#include <vector>
#include <string>
#include <sstream>
#include <numeric>

#define rep(i, j) for(int i = 0; i < j; i++)
#define all(i) i.begin(), i.end()
#define ll long long
#define bl bool
#define nn printf("\n");
#define mod 1000000007

using namespace std;

int main()
{
	cin.tie(0);
	ios::sync_with_stdio(false);

	while (1)
	{
		int N = 0; cin >> N;
		if (N == 0) { break; }
		vector<int> num(N, 0);
		int ans = 0;
		rep(i, N){ num[i] = i + 1; }
		rep(i, N)
		{
			for(int j = i; j<N; j++)
			{
				if (accumulate(num.begin() + i, num.begin() + j, 0) == N)
				{
					ans += 1;
				}
			}
		}
		printf("%d\n", ans);
	}

	return 0;
}