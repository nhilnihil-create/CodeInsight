#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
   	
int main() {
	int n, s1 = 0, s2 = 0, diff = 10007, dif;

	cin >> n;

	int a[n];

	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}

	for (int i = 1; i < n; i++)
	{
		s1 = s2 = 0;
		for (int j = 0; j < i; j++)
		{
			s1 = s1 + a[j];
		}

		for (int k = i; k < n; k++)
		{
			s2 = s2 + a[k];
		}
		if ((s1 - s2) < 0)
		{
			dif = s2-s1;
		}
		else
		{
			dif = s1 -  s2;
		}

		diff = min(diff, dif);

	}

	cout << diff ;

	return 0;
}

