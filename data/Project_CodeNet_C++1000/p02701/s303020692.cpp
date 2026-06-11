#include <iostream>
#include <map>
using namespace std;
int main()
{
	int n, sum = 0;
	cin >> n;
	string s;
	map<string, int> m;
	for (int i = 1; i <= n; i++)
	{
		cin >> s;
		if (m[s] == 0)
			sum++;
		m[s]++;
	}
	cout << sum;
	return 0;
}