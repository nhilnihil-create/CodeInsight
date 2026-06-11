#include<bits/stdc++.h>
#define mp make_pair
#define pr pair<ll,ll>
#define MAX 1000000
#define ed '\n'
using namespace std;
typedef long long int ll;
#define mod 998244353
void sync(){
ios_base::sync_with_stdio(false);
cin.tie(NULL);
cout.tie(NULL);
}

int main(){
	sync();
	ll n;
	cin>>n;
	ll fin=0;
	for(ll i=2;i*i<=n-1;i++)
	{
		if((n-1)%i==0)
		{
			if(i*i==n-1)fin++;
			else fin+=2;
			}	
	}
	if(n-1!=1)
	fin++;
	for(ll i=2;i*i<=n;i++)
	{
		if(n%i==0)
		{
		ll n1=n;
		ll j=n/i;
		while(n1%i==0)n1/=i;
		if((n1-1)%i==0)fin++;
		n1=n;
		if(i!=j)
		{while(n1%j==0)n1/=j;
		if((n1-1)%j==0)fin++;
		}
		}
	}
	fin++;
	cout<<fin<<endl;
}