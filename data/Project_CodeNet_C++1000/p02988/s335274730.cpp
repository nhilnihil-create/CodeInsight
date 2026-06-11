#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define int long long
int32_t main()
{


	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	int arr[n], count = 0;;
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}
	for (int i = 1; i < n - 1; i++)
	{
		if ((arr[i] > arr[i - 1] && arr[i] < arr[i + 1]) || (arr[i] < arr[i - 1] && arr[i] > arr[i + 1]))
			count++;
	}
	cout << count;
}