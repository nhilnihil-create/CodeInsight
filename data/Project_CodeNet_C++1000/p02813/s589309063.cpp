#include<bits/stdc++.h>
using namespace std;
#define ll long long int
const long long int  mod  = 1000000007;
int main()
{
	int n,pp,ppp;
	ll i;
	cin>>n;
	vector<int> v,a(n),b(n);
	for(i=0;i<n;i++)
	{
		cin>>a[i];
		v.push_back(a[i]);
	}
	for(i=0;i<n;i++)
		cin>>b[i];
	sort(v.begin(),v.end());
	ll k=0;
	do
	{
		int flag=1,smit=1;
		for(i=0;i<n;i++)
		{
			if(v[i]!=a[i])
			{
				flag=0;
				break;
			}
		}
		if(flag==1)
		{
			pp=k;
		}
		for(i=0;i<n;i++)
		{
			if(v[i]!=b[i])
			{
				smit=0;
				break;
			}
		}
		if(smit==1)
		{
			ppp=k;
		}
		k++;
	}while(next_permutation(v.begin(), v.end()));
	cout<<abs(pp-ppp);
}
