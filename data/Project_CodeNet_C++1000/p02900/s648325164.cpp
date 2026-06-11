#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
	ll a,b;
	cin>>a>>b;
	vector<ll>pos1;
	vector<ll>pos2;
	for(ll i=2; i*i<=a; i++)
	{
		if(a%i==0)
		{
			pos1.push_back(i);
			while(a%i==0)
			{
				a=a/i;
			}
		}
	}
	if(a>1)
	 pos1.push_back(a);
	for(ll i=2; i*i<=b; i++)
	{
		if(b%i==0)
		{
			pos2.push_back(i);
			while(b%i==0)
			{
				b=b/i;
			}
		}
	}
	if(b>1)
	{
		pos2.push_back(b);
	}
	int cnt=1;
	sort(pos1.begin(),pos1.end());
	sort(pos2.begin(),pos2.end());
	for(int i=0; i<pos1.size(); i++)
	{
		if(binary_search(pos2.begin(),pos2.end(),pos1[i]))
		{
			cnt++;
		}
	}
	cout<<cnt;
	return 0;
}