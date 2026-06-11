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
	int a[100], b[100];
	int n;
	double p1 = 0.0, p2 = 0.0, p3 = 0.0, pi = 0.0;

	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	for (int i = 0; i < n; i++)
	{
		cin >> b[i];
	}

	for (int i = 0; i < n; i++)
	{
		p1 += abs(a[i] - b[i]);
	}

	for (int i = 0; i < n; i++)
	{
		p2 += abs(a[i] - b[i])*abs(a[i] - b[i]);
	}
	p2 = sqrt(p2);

	for (int i = 0; i < n; i++)
	{
		p3 += abs(a[i] - b[i])*abs(a[i] - b[i])*abs(a[i] - b[i]);
	}
	p3 = pow(p3, 1.0 / 3.0);

	pi = abs(a[0] - b[0]);
	for (int i = 0; i < n; i++)
	{
		pi = max(pi, abs(a[i] - b[i]));
	}

	printf("%lf\n%lf\n%lf\n%lf\n", p1, p2, p3, pi);
}