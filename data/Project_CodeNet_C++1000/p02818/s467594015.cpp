#include<bits/stdc++.h>
const int M=1e9+7;// M=1e9+7;//M=300000;//
const int N=1e5+5;
typedef long long int ll;
using namespace std;
 
ll cnt(0),n,m,x,y,i,j,temp,t,k,ans(0),sum(0),mn(M),mx(-9e9);

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	cin>>x>>y>>k;
	if(x<=k)
	{
		k-=x;
		x=0;
	}else{
		x-=k;
		k=0;
	}
	if(y<=k)
	{
		k-=y;
		y=0;
	}else{
		y-=k;
		k=0;
	}
	cout<<x<<" "<<y;
	
}