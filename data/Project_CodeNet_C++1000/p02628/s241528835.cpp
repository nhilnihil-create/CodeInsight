#include <iostream>
#include<string>
#include<algorithm>
#include<vector>
using namespace std;
int main()
{
	int n, k,p[1000];
	cin >> n >> k;
	for (size_t i = 0; i < n; i++)
	{ 
		int x;
		cin >> x;
		p[i] = x;
	}
	sort(p, p + n);
	int sum = 0;
	for (size_t i = 0; i < k; i++)
	{
		sum += p[i];
	}
	cout << sum<<endl;
	return 0;
}