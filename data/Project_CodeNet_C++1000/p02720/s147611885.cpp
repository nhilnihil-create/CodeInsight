#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
vector<ll> v;
int main()
{
	ll n;cin>>n;
	for (int i = 1; i <= 9; i++)
	{
		v.push_back(i);
	}
	ll t=9;
	ll first=0;
	while(1)
	{
		if(t>100001) break;
		ll top=v[first];
		if(top%10==0)
		{
			v.push_back(top*10);
			v.push_back(top*10+1);
			t+=2;
		}
		else if(top%10==9)
		{
			v.push_back(top*10+8);
			v.push_back(top*10+9);
			t+=2;
		}
		else
		{
			ll tt=top%10;
			v.push_back(top*10+tt-1);
			v.push_back(top*10+tt);
			v.push_back(top*10+tt+1);
			t+=3;
		}
		first++;
	}
	cout<<v[n-1]<<endl;

	
}