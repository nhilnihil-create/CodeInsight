#include<bits/stdc++.h>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin>>n;
	bool ok = false;
	unsigned long long ans = 1,test = 1e18;
	long long res;	
	while(n--)
	{
		unsigned long long x;
		cin>>x;
		if(x==0)
			ok = true, res = 0;
		if(!ok)
		{
			if(log10(ans)+log10(x)<=18.0)
			{
				ans *= x;
				if(ans>test)
					ok = true, res = -1;
				else res = ans;
			}
			else ok = true, res = -1;
		}
	}
	cout<<res<<endl;
	return 0;
}