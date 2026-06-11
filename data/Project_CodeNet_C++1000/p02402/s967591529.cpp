

#include<iostream>

using namespace std;

int main()
{
	int n, i, tmp;
	int num[10000];
	long sum = 0;

	cin >> n;

	for (i = 0; i < n; i++)
	{
		cin >> num[i];
	}

	for (i = 0; i < n-1; i++)
	{
		if (num[i] < num[i + 1])
    	{
			tmp = num[i + 1];
			num[i + 1] = num[i];
			num[i] = tmp;
		}
	}
	cout << num[n-1] << " ";

	for (i = 0; i < n - 1; i++)
	{
		if (num[i] > num[i + 1])
		{
			tmp = num[i + 1];
			num[i + 1] = num[i];
			num[i] = tmp;
		}
	}

	for (i = 0; i < n; i++)
	{
		sum += num[i];
	}
	cout << num[n-1] << " " << sum << endl;

	return 0;
}