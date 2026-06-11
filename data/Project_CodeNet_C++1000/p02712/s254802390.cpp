#include <bits/stdc++.h>

using namespace std;

int main(void)
{
	cin.tie(0);
	ios::sync_with_stdio(false);

	long long int res = 0;
  	int n;
  
	cin >> n;

	for(int i=1;i<=n;i++)
	{
		if(i%3!=0 && i%5!=0)
		{
			res += i;
		}
	}

	cout << res << '\n';
	
	return 0;
}
