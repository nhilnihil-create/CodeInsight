#include<sstream>
#include<string>
#include<algorithm>
#include<cmath>
#include<vector>
#include<iostream>
int main()
{
	int h, n, sum = 0;
	std :: cin >> h >> n;
	int a[n];
	for(int i = 0; i < n; i++)
	{
		std :: cin >> a[i];
		sum = sum + a[i];
	}
	if(sum >= h)
		std :: cout << "Yes";
	else
		std :: cout << "No";
}