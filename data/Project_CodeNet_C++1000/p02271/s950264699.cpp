#include <iostream>
#include <string>
#include <algorithm>
#include <cstdio>

using namespace std;



int main()
{
	int n,q,a,m,last,temp=0;
	bool dp[2001]={0};

	cin >> n;

	dp[0] = true;
	last = 0;

	for(int i = 0; i < n; i++)
	{
		cin >> a;
		temp = 0;

		for(int j = last; j >= 0; j--)
		{
			if (dp[j])
			{
				temp = max(j+a,temp);
				dp[j + a] = true;
			}
		}

		last = max(temp,last);
	}

	cin >> q;

	for(int i = 0; i < q; i++)
	{
		cin >> m;

		if (dp[m])
		{
			cout << "yes" << endl;
		}else
		{
			cout << "no" << endl;
		}
	}

	return 0;
}
	