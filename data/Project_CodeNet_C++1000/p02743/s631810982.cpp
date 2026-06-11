#include<bits/stdc++.h>
using namespace std;
signed main()
{
	long long ans1,ans2,a,b,c;
	cin>>a>>b>>c;
	ans1=4*a*b;
	if((c-a-b)<=0)
	{
	cout<<"No\n";
	return 0;
	}
	ans2=(c-a-b)*(c-a-b);
	if(ans1<ans2)cout<<"Yes\n";
	else cout<<"No\n"; 
    return 0;
}
