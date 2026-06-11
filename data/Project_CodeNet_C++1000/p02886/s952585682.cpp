#include<bits/stdc++.h>
using namespace std;


int main()
{
	int n; cin >> n;
	int ans = 0, sum = 0;
	for (int i = 0; i < n; ++i)
	{
		int a; cin >> a;
		ans += sum * a;
		sum += a;
	}
	cout << ans << endl;
}

