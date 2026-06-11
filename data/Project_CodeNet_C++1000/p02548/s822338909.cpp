#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;
int main()
{
	long long n, res = 0, tmp, ka = 0, cnt = 1;
	cin >> n;
	for (int i = 1; i <= sqrt(n); i++)
	{
		ka = (n - 1) / cnt;
		tmp = ka - i;
		if (tmp >= 1) res += tmp * 2 + 1;
		else if (tmp == 0) res += 1;
		cnt++;
	}
	cout << res << endl;
	return 0;
}