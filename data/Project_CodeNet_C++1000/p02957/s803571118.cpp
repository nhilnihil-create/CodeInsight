#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
	ll a,b;
	cin>>a>>b;
	ll sub=abs(a-b)/2;
	if(sub*2==abs(a-b))
	cout<<sub+min(a,b);
	else
	cout<<"IMPOSSIBLE";
	return 0;
}