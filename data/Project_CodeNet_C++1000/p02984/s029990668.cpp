#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int mod=1e9+7;
ll m,n,yy[100005],sum; 

int main()
{
    std::ios::sync_with_stdio(0); std::cin.tie(0);
    cin>>m;
    for(int i=1;i<=m;++i)
    {
    	cin>>yy[i];
    	if(i%2) sum+=yy[i],n-=2*yy[i];
    	else sum-=yy[i],n+=2*yy[i];
	}
	cout<<sum<<" ";
	n+=2*yy[1];
	for(int i=1;i<m;++i)
	{
		sum=sum+n;
		cout<<sum<<" ";
		n=n+2*yy[i]-2*yy[i+1];
		n=-n;
	}
 	return 0;
}