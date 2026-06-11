#include<bits/stdc++.h>
#include<algorithm>
using namespace std;
#define ll long long

ll lcmOf2(int a,int b=360)
{
	int Max=max(a,b);
	ll lcm=Max;
	while(lcm%a!=0 || lcm%b!=0)
	{
		lcm+=Max;
	}
	return lcm;
}

int main()
{
	int x;
	cin>>x;
	
	ll lcm=lcmOf2(x);
	
	cout<<lcm/x<<endl; 
	
	return 0;   
}