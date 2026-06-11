#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MAX=1e18;
const int N=1e5+10;
ll a[N];
int main()
{
	ll n;
	ll cnt=1;
	cin>>n;
	int zero=0;
	for(ll i=0;i<n;i++) {
		cin>>a[i];
		if(!a[i]) zero++;
	}
	if(zero>0) cout<<0<<endl;
	else 
	{
		for(ll i=0;i<n;i++) 
		{
			if(a[i]<=MAX/cnt) cnt*=a[i];
			else
			{
				cout<<-1<<endl;
				return 0;
			}
		}
		cout<<cnt<<endl;
	}
	return 0;
}