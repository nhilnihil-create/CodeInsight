#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
	ll n;
	cin>>n;
	ll sum1=0;
	for(int i=3; i<=n; i+=3)
	 sum1-=i;
	for(int i=5; i<=n; i+=5)
	 sum1-=i;
	for(int i=15; i<=n; i+=15)
	 sum1+=i;
	for(int i=1; i<=n; i++)
	 sum1+=i;
	cout<<sum1;
	return 0;
	
}