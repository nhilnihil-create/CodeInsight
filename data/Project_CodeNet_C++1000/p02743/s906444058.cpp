
#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{

	ios_base::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);

	// #ifndef ONLINE_JUDGE
 //    freopen("input.txt" , "r" , stdin);
	// freopen("output.txt" , "w" , stdout);
	// #endif

	ll a,b,c;
	cin>>a>>b>>c;
	if(c-a-b>=0)
	{
		if(4*a*b<(c-a-b)*(c-a-b))
			cout<<"Yes"<<endl;
		else
			cout<<"No"<<endl;
	}
	else
		cout<<"No"<<endl;

	
	
}
