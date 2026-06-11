#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
	ll x,y,a,b,c;
	cin>>x>>y>>a>>b>>c;
	vector<ll>red(a);
	vector<ll>green(b);
	vector<ll>no(c);
	for(int i=0; i<a; i++)
	 cin>>red[i];
	sort(red.rbegin(),red.rend());
	for(int i=0; i<b; i++)
	 cin>>green[i];
	sort(green.rbegin(),green.rend());
    for(int i=0; i<c; i++)
	 cin>>no[i];
	vector<ll>pos;
	for(int i=0; i<min(a,x); i++)
	{
		pos.push_back(red[i]);
	}
	for(int i=0; i<min(b,y); i++)
	 pos.push_back(green[i]);
	for(int i=0; i<c; i++)
	 pos.push_back(no[i]);
	sort(pos.rbegin(),pos.rend());
	ll sum=0;
	for(int i=0; i<x+y; i++)
	 sum+=pos[i];
	cout<<sum;
	return 0;	
	
}