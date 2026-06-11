#include <bits/stdc++.h>
     
using namespace std;

int main(void)
{
	cin.tie(0);
	ios::sync_with_stdio(false);

	int n;

	cin >> n;

	if(n%2==0)
	{
		cout << n/2-1 << '\n';
	}
	else
	{
		cout << n/2 << '\n';
	}
	
	return 0;
}
