#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define pi 3.141592653589793238
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define MOD 1000000007
int main()
{
	fast;
	double h,w,x,y;
	cin>>w>>h>>x>>y;
	double ans1=0,ans2=0,ans;
	if(x*2==w&&y*2==h)
		ans2=1;
	cout<<fixed<<setprecision(9)<<h*w/2.0<<" ";
	cout<<fixed<<setprecision(0)<<ans2;
	return 0;
}
