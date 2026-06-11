#include <iostream>
#include <cstring>
#include<vector>
#include <algorithm>
#include<cstdlib>
#include<set>
#include<math.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
#define rep(i,n) for(ll i=0;i<n;i++)

int main()
{
	int n;
	cin >> n;
	string ans = "No";
	for (int x = 1; x < 10; x++)
	{
		for (int y = x; y < 10; y++)
		{
			if (n == x * y)
			{
				ans = "Yes";
			}
		}
	}
	
	cout << ans << "\n";


	return 0;
}