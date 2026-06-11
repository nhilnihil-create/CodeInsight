#include<bits/stdc++.h>
#define ft(i,l,r) for(register int i=l;i<=r;i++)
#define fd(i,r,l) for(register int i=r;i>=l;i--)
using namespace std;
int n,m,ans;
double a[15][15],s;
int main()
{
	cin>>n>>m;
	ft(i,1,n)
	  ft(j,1,m)
	    cin>>a[i][j];
	ft(i,1,n)
	  ft(j,i+1,n)
	  {
	  	  s=0.0;
	  	  ft(k,1,m) s+=(double)(1.0*(1.0*a[i][k]-a[j][k])*(1.0*a[i][k]-a[j][k]));
	  	  s=sqrt(s);
	  	  if(int(s)==s) ans++;
	  }
	cout<<ans;
	return 0;
}