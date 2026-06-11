#include<iostream>
#include<algorithm>
#include<cstring>

using namespace std;

int a[200000], b[200000];

int main()
{
	int k,n;
	cin >> k >> n ;

	for (int i = 0; i < n; i++)
		cin >> a[i];

	for (int i = 0; i < n-1; i++)
		b[i] = a[i + 1] - a[i];

	b[n - 1] = (k - a[n - 1]) + a[0];

	sort(b, b + n);

	cout << k - b[n - 1];
}