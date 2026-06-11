#include<bits/stdc++.h>
const int M=1e9+7;// M=1e9+7;//M=300000;//
const int N=2e5+5;
typedef long long int ll;
using namespace std;
 
ll cnt(0),sum(0),n,m,x,y,t,i,j,temp,k,ans(1),mn(M),mx(-9e9);
vector<ll> v;
ll mark[N];
ll a[100][100];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cin>>x>>y;i=0,j=x;
	while(1)
	{
		temp=(i*2+j*4);
		if(temp==y)
		{
			cout<<"Yes";
			return 0;
		}
		i++;
		j--;
		if(i>x)
		{
			break;
		}
	}
	cout<<"No";
}