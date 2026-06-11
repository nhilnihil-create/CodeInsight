#include <bits/stdc++.h>

using namespace std;

int main() 
{
	cin.tie(0);
	ios::sync_with_stdio(false);
	
	long long int n;
	long long int res = 1;
	set <long long int> S;
	cin >> n;
	
	long long int m = n - 1;
	
	for(long long int i=2;i<=sqrt(m);i++)
	{
		if(m%i==0)
		{
			if(i*i==m)
			{
				S.insert(i);
			}
			else
			{
				S.insert(m/i);
				S.insert(i);
			}
		}
	}
	if(m!=1)
	{
		S.insert(m);
	}
	for(long long int i=2;i<=sqrt(n);i++)
	{
		if(n%i==0)
		{
			long long int a = i;
			long long int b = n/i;
			if(a==b)
			{
				long long int temp = n;
				while(1)
				{
					if(temp%a!=0)
					{
						break;
					}
					temp/=a;
				}
				temp%=a;
				if(temp==1)
				{
					S.insert(a);
				}
				temp = n;
				while(1)
				{
					if(temp%b!=0)
					{
						break;
					}
					temp/=b;
				}
				temp%=b;
				if(temp==1)
				{
					S.insert(b);
				}				
			}
			else
			{
				long long int temp = n;
				while(1)
				{
					if(temp%a!=0)
					{
						break;
					}
					temp/=a;
				}
				temp%=a;
				if(temp==1)
				{
					S.insert(a);
				}				
			}
		}
	}
	
	if(n!=1)
	{
		S.insert(n);
	}
	
	cout << S.size() << '\n';
	
	return 0;
}