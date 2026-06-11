#include <bits/stdc++.h>

using namespace std;

int main()
{
	long long int H, W;
	long long int ans;

	cin >> H >> W;


	if (H == 1 || W == 1)
		ans = 1;
	else
	{
		ans = H * W / 2;

		if (H % 2 == 1 && W % 2 == 1)
			ans += 1;
	}

	cout << ans << endl;



}