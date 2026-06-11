#include<iostream>
#include<string>
#include<vector>
using namespace std;
int main()
{
	/*int n, r;
	cin >> n >> r;
	if (n >= 10)
		cout << r;
	else
		cout << r + (10 - n) * 100;*/

	long long n, k = 0;
	cin >> n >> k;
	int ans = 1;
	while (n >= k)
	{
		n /= k;
		ans += 1;
	}
	cout << ans;
}

