#include <bits/stdc++.h>
#define ll long long
#define endl "\n"
#define the_flash ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define input_output freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout)

using namespace std;

int main()
{
	//input_output;
	the_flash;
	int n, count = 1;
	cin >> n;
	int arr[n];

	for (int i = 0; i < n; i++)
		cin >> arr[i];

	for (int i = 0; i < n - 1; i++)
	{
		if (arr[i] > arr[i + 1])
			count++;

		else
			arr[i + 1] = arr[i];
	}

	cout << count << endl;
	return 0;
}