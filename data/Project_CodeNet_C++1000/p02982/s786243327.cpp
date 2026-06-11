#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
   	
int main() {
	int counter = 0;
	int n, d;

	cin >> n >> d;
	double sum = 0;
	double x[n][d];

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < d; j++)
		{
			cin >> x[i][j];
		}
	}

	for (int i = 0; i < n-1; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			sum = 0;
			for (int k = 0; k < d; k++)
			{
				sum = sum + (x[i][k] - x[j][k])*(x[i][k] - x[j][k]);
			} 
			sum = sqrt(sum);
			// cout << sum;
			if (ceil(sum) == floor(sum))
			{
				counter++;
			}
		}
	}

	cout << counter;

    return 0;
}

