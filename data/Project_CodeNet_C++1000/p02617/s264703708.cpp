
#include "math.h"
#include <iostream>
#include <fstream>
#include <algorithm>
#include <string>
#include <map>
#include <vector>
#include <functional>
#include <numeric>
#include <cmath>
using namespace std;

int main()
{
	int n;
	cin >> n;
	long long ans = 0;
	for (int i = 0; i < n; i++)
	{
		//vertices
		ans += 1LL*(i+1)*(n - i);
	}
	for (int i = 0; i < n-1; i++)
	{
		int u, v;
		cin >> u >> v;
		//edges
		if (u<=v)
		{
			ans -= 1LL*(u) * (n - v+1);
		}
		else {
			ans -= 1LL*(v) * (n - u+1);
		}
	}
	cout << ans;
	return 0;
}
