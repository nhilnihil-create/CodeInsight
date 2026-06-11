#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
	ll n,p;
	cin>>n>>p;
	string s;
	cin>>s;
	ll cnt=0;
	int size=s.size();
	vector<int>arr(size);
	for(int i=0; i<size; i++)
	 arr[i]=s[i]-48;
	if(p==2)
	{
		for(ll i=size-1; i>=0; i--)
		{
			if(arr[i]==0)
			{
				cnt+=i+1;
			}
			else if(arr[i]%2==0)
			{
				cnt+=(i+1);
			}
		}
	}
	else if(p==5)
	{
		for(ll i=size-1; i>=0; i--)
		{
			if(arr[i]==0)
			 cnt+=i+1;
			else if(arr[i]==5)
			 cnt+=(i+1);
		}
	}
	else
	{
		map<int,int>rel;
		rel[0]=1;
		vector<int>rem(size+1,0);
		ll pr=1%p;
		for(ll i=size-1; i>=0; i--)
		{
			rem[i]=(rem[i+1]+arr[i]*pr%p)%p;
			cnt+=rel[rem[i]];
			pr=pr*10%p;
			rel[rem[i]]++;
	    }
    }
    cout<<cnt;
	return 0;
}