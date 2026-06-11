#include<bits/stdc++.h>
using namespace std;


int main()
{
	int n; cin >> n;
	int ans;
	for (int i = 1; i < 11; ++i)
		if (i * 1000 >= n)
		{
			ans = i * 1000 - n;
			break;
		}
	cout << ans << endl;
}

