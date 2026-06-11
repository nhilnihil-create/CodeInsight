#include <iostream>
#include <vector>
#include <math.h>
#include <string>
#include <algorithm>
using namespace std;

long long l = 2000001;
vector<long long> b(l, 0);

long long func(long long n)
{
	return n * (n - 1) / 2;
}

int main(void) {
	int n;
	cin >> n;

	vector<int> a(n);

	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
		b[a[i]]++;
	}

	long long sum = 0;

	for (int i = 1; i < l; i++)
	{
		sum += b[i] * (b[i] - 1) / 2;
	}

	for (int i = 0; i < n; i++)
	{
		cout << sum - func(b[a[i]]) + func(b[a[i]] - 1) << endl;
	}

	return 0;
}