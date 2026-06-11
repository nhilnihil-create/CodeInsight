#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define mem(a, b) memset(a, b, sizeof(a))
#define IOS() std::ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
int f(int x)
{
	if(x==1) return 300000;
	if(x==2) return 200000;
	if(x==3) return 100000;
	return 0;
}
int main()
{

	IOS();
	int a,b;
	while(cin>>a>>b)
	{
		int ans=f(a)+f(b);
		if(ans==600000) ans+=400000;
		cout<<ans<<endl;
	}
	return 0;
}