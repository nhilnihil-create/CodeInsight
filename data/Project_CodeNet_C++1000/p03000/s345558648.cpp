#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
   	
int main() {
	int n,x;
	int sum = 0;
	int counter = 1;

	cin >> n >> x;

	int l[n];

	for (int i = 0; i < n; i++)
	{
		cin >> l[i];
	}

	for (int i = 0; i < n; i++)
	{
		sum = sum + l[i];
		if (sum <= x)
		{
			counter++;
		}
		else
		{
			break;
		}
	}
	cout << counter  ;

	return 0;
}

