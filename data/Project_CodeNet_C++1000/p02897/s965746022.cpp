#include<bits/stdc++.h>
using namespace std;
#define nl '\n' 
#define fast ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define ll long long int
#define pii pair <int,int>
ll mod=1000000007;
int main()
{
	fast;
	int n;cin>>n;
	double ans;
	if(n==1)
		ans=1;
	else if(n%2==0)
		ans=(double)(n/2)/n;
	else
		ans=(double)((n/2) +1)/n;
	cout<<fixed<<setprecision(10)<<ans;
}