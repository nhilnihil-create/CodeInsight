#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll k;
set<int> s;
ll bm(ll a,ll b)
{
	if(b==0) return 1;
	ll t=bm(a,b/2);
	if(b%2==0) return t*t%k;
	else return a*(t*t%k)%k;
}
int main()
{
	cin>>k;
	if(k%2==0)
	{
		cout<<"-1"<<endl;
		return 0;
	}
	if(k%7==0) k/=7;
	k*=9;
	ll i=1;
	while(i)
	{
		ll now=bm(10,i);
		if(s.count(now))
		{
			cout<<"-1"<<endl;
			return 0;
		}
		if(now==1) 
		{
			cout<<i<<endl;
			return 0;
		}
		s.insert(now);
		i++;
	}
}