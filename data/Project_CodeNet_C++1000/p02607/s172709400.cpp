#include <iostream>
#include<string>
#include<algorithm>
#include<vector>
using namespace std;
int main()
{
	int n, s[100];
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> s[i];
	}
	int sum = 0;
	for (int i = 0; i < n; i+=2)
	{
		if (s[i] % 2)
			sum++;
	}
	cout << sum << endl;
	return 0;
}