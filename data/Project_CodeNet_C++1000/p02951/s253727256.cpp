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

	int a,b,c;
	cin>>a>>b>>c;
	if(a>=b+c)
		cout<<0<<endl;
	else
	{
		cout<<b+c-a<<endl;
	}
	
}
