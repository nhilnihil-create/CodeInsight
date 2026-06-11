#include<iostream>
#include<string>
using namespace std;
int main()
{
	//string duck;
	//getline(cin,duck);
	//if (duck == "ABC")
	//	cout << "ARC";
	//else cout << "ABC";

	int n, k = 0;
	cin >> n >> k;
	int *arr = new int[n];

	for (int i = 0; i < n; i++)
	{
		arr[i] = 0;
	}

	for (int i = 0; i < k; i++) 
	{
		int duck;
		cin >> duck;
		for (int j = 0; j < duck; j++) 
		{
			int a = 0;
			cin >> a;
			arr[a - 1] += 1;
		}
	}

	int ans = 0;
	
	for (int i = 0; i < n; i++)
	{
		if (arr[i] == 0)
			ans += 1;
	}
	cout << ans;


    return 0;
}
