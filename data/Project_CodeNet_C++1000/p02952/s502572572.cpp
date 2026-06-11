#include <bits/stdc++.h>

using namespace std;

int main(void)
{
	cin.tie(0);
	ios::sync_with_stdio(false);

	int N;
	int res = 0;

	cin >> N;

	for(int i=1;i<=N;i++)
	{
		int cnt = 0;
		int val = i;
		while(val > 0)
		{
			cnt++;
			val/=10;
		}
		if(cnt%2==1)
		{
			res++;
		}
	}

	cout << res << '\n';
	
	return 0;
}
