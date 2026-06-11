#include <iostream>
#include <cstdio>
#include <cmath>
#include <cctype>
#include <cstdlib>
#include <algorithm>
#include <string>
#include <iomanip>

using namespace std;

#define pi 3.141592653589
#define repeat(i,n) for(int i=0;i<n;i++)

int n;
int *x, *y;

void solve(int n)
{
	x = new int[n];
	y = new int[n];

	//2つのn次元ベクトルを形成
	repeat(i, n)
	{
		cin >> x[i];
	}
	repeat(i, n)
	{
		cin >> y[i];
	}

	//p=1(マンハッタン距離)
	double sum = 0;
	repeat(i, n)
	{
		sum += abs(x[i] - y[i]);
	}
	cout << fixed << setprecision(5) << sum << endl;

	//p=2(ユークリッド距離)
	sum = 0;
	repeat(i, n)
	{
		sum += pow(x[i] - y[i], 2);
	}
	cout << fixed << setprecision(5) << sqrt(sum) << endl;

	//p=3
	sum = 0;
	repeat(i, n)
	{
		sum += abs(pow(x[i] - y[i], 3));
	}
	cout << fixed << setprecision(5) << cbrt(sum) << endl;

	//p=∞(チェビシェフ距離)
	sum = 0;
	double max = 0;
	repeat(i, n)
	{
		if (abs(x[i] - y[i]) >= max) max = abs(x[i] - y[i]);
	}
	cout << fixed << setprecision(5) << max << endl;

	return;
}

int main()
{
	while (cin >> n)
	{
		solve(n);
	}
	return 0;
}