#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
   	
int main() {
	int n, l, sum = 0, val, ind;

	cin >> n >> l;
	int a[n];
    val = l;
	for (int i = 1; i < n+1; i++)
	{
		sum = sum + l + i - 1;
		a[i - 1] = l + i - 1;
		if (a[i-1] < 0)
		{
			if (val < 0)
			{
				if (((-1) * a[i-1]) < ((-1)*val))
				{
					val = a[i-1];
				}
			}
			else
			{
				if (((-1) * a[i-1]) < val)
				{
					val = a[i-1];
				}
			}
		}
		else
		{
			if (val < 0)
			{
				if (a[i-1] < ((-1)*val))
				{
					val = a[i-1];
				}
			}
			else
			{
				if (a[i-1] < val)
				{
					val = a[i-1];
				}
			}
		}
	}

	sum = sum - val;
	cout << sum ;

	return 0;
}

