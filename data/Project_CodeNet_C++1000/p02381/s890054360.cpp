#include<cstdio>
#include<vector>
#include<algorithm>
#include<utility>
#include<numeric>
#include<iostream>
#include<array>
#include<string>
#define _USE_MATH_DEFINES

#include<math.h>
#include<unordered_map>

#define min(a,b) (a)>(b)?(b):(a)
#define max(a,b) (a)>(b)?(a):(b)

using namespace std;

int main()
{
	int s[1000];
	int n;

	while (true)
	{
		cin >> n;

		if (n == 0)
		{
			break;
		}

		double ave = 0.0;
		for (int i = 0; i < n; i++)
		{
			cin >> s[i];
			ave += s[i];
		}
		ave /= (double)n;

		double alpha = 0.0;
		for (int i = 0; i < n; i++)
		{
			alpha += (s[i] - ave)*(s[i] - ave);
		}
		alpha /= (double)n;
		printf("%lf\n", sqrt(alpha));
	}
}