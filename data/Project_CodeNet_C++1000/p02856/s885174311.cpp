#include <bits/stdc++.h>
     
using namespace std;

int main(void)
{
	cin.tie(0);
	ios::sync_with_stdio(false);

	unsigned long long int res = 0;
	int m;
	long long int d,c;
	long long int len = 0;
	vector <int> v;

	cin >> m;

	for(int i=0;i<m;i++)
	{
		cin >> d >> c;
		int now = d;
		while(c>0)
		{
			if(c%2==1)
			{
				v.push_back(now);
			}
			res += (c/2);
			now+=now;
			if(now>=10)
			{
				res += c/2;
				now = (now/10) + (now%10);
			}
			c/=2;
		}
	}

	if(v.size()>=2)
	{
		int now = v[0];
		for(int i=1;i<v.size();i++)
		{
			now += v[i];
			res++;
			if(now>=10)
			{
				res += 1;
				now = (now/10) + (now%10);
			}
		}
	}

	cout << res << '\n';

	return 0;
}