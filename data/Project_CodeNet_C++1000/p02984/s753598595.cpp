#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
   	
int main() {
	long long int n, sum = 0, total = 0;
	cin >> n;

	long long int a[n], x[n];

	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
		total = total + a[i];
	}

	for (int i = 1; i < n; i = i + 2)
	{
		sum = sum + 2*a[i];
	}

	x[0] = total - sum;

	for (int i = 1; i < n; i++)
	{
		x[i] = a[i-1]*2 - x[i-1];
 	}

 	for (int i = 0; i < n; i++)
 	{
 		cout << x[i] << " ";
 	}

	return 0;
}

