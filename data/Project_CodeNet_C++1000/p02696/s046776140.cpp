#include<bits/stdc++.h>
using namespace std;
#define read(x) scanf("%d",&x)
#define readl(x) scanf("%lld",&x)
#define ll long long 
#define ull unsigned long long
ll a,b,n;
ll x;
int main()
{
	cin>>a>>b>>n;
	if(n<b) x=n;
	else x=b-1;
	cout<<floor((double)a*(double(x)/b-floor(double(x)/b)))<<endl;
	return 0;
}