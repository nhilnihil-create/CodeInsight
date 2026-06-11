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
	int n, maxN = 0;
	cin >> n;
	vector<int> h(n);
	rep(i, n) cin >> h[i];
	for(int i = 0; i < n; i++)
	{
		int count = 0;
		for(int j = 0; i+j+1 < n; j++)
		{
			if (h[i+j+1] > h[i+j]) break;
 			count++;
		}
		maxN = max(maxN, count);
	}
	cout << maxN;
	return 0;
}