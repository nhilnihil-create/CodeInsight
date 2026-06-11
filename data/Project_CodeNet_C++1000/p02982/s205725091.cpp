#include <iostream>
#include <stack>
#include <math.h>
#include <vector>
#include <string>
#include <algorithm>
#include <map>

#define rep(i,n) for(int i=0; i < n; i++)
using ll =  long long;
using namespace std;
#define pi 3.14159265358979


int main()
{
	int n, d, count = 0;
	cin >> n >> d;
	vector<vector<int>> a(n, vector<int>(d));

	rep(i, n)rep(j, d)  cin >> a[i][j];

	for (int i = 0; i < n; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			double x = 0.0;
			rep(k, d) x += pow((a[i][k] - a[j][k]), 2);

			if (sqrt(x) - (int)sqrt(x) == 0) count++;
		}
	}
	cout << count;
	return 0;
}