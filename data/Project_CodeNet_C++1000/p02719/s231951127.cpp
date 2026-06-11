#include<iostream>
#include<algorithm>
#include<vector>
#include<cstring>
#define ll long long
using namespace std;
ll t,n;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	ll k;
	while(cin>>n>>k)
	{
		ll a=n/k;
		if(n%k)
		cout<<min(min(k,n),abs(k-n%k))<<endl; 
		else
		cout<<0<<endl;
	}
	return 0;
}