#include <iostream>
using namespace std;

int main()
{
	int n, cnt = 0, nb;
	cin >> n;
	for (int i = 1; i <= n; ++i)
	{
		cin >> nb;
		if (i % 2 != 0 && nb % 2 != 0)
		{
			cnt++;
		}
	}
	cout << cnt << endl;
	ios::sync_with_stdio(false);
	cin.tie();
	cout.tie();
	return 0;
}