#include <iostream>
#include <algorithm>
using namespace std;

 long int n,a[10000000];
int main()
{
	long int MIN = 10000000,MAX = -10000000,total = 0;

	cin >> n;
	for(int i = 0; i < n; i++)
	{
		cin >> a[i];
		total += a[i];
		MIN = min(MIN,a[i]);
		MAX = max(MAX,a[i]);
	}

	cout << MIN << " " << MAX << " " << total << endl;

	return 0;
}