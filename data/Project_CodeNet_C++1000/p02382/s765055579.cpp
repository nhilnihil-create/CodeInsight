#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
#include<cstdio>

using namespace std;


int main()
{
	int n;
	double x[101];
	double y[101];
	cin >> n;
	for (int i = 0; i < n; i++)cin >> x[i];
	for (int i = 0; i < n; i++)cin >> y[i];
	double m=0;
	for (int i = 0; i < n; i++)
	{
		m += abs(x[i] - y[i]);
	}
	cout <<fixed<< m << endl;
	m = 0;
	for (int i = 0; i < n; i++)
	{
		m += abs(x[i] - y[i])*abs(x[i] - y[i]);
	}
	m = sqrt(m);
	cout << m<<endl;
	//3次元
	m = 0;
	for (int i = 0; i < n; i++)
	{
		m += abs(x[i] - y[i])*abs(x[i] - y[i])*abs(x[i] - y[i]);
	}
	m = cbrt(m);
	cout << m << endl;

	m = 0;
	for (int i = 0; i < n; i++)
	{
		m = max(m, abs(x[i] - y[i]));
	}
	cout << m;
}