#include<iostream>
using namespace std;
#define ll long long
const int maxn=5050;
const ll inf1=1e16+9;
ll a[maxn][maxn];
ll P[maxn],C[maxn];
ll n,k;
ll solve(int i)
{    ll j,ans;
     ll  Max=-inf1;
    ans=1;j=P[i]; 
    do
    {   a[i][ans]=a[i][ans-1]+C[j];
	   if(ans<=k&&Max<a[i][ans])
         Max=a[i][ans];
	   j=P[j];
	   ans++;
	   if(ans>k) break;
	}while(P[i]!=j);
	a[i][0]=ans-1;
	//printf("%lld ",a[i][1]);
    //	for(int j=0;j<=ans-1;j++)printf("%lld ",a[i][j]);printf("             %lld",Max);printf("\n");
	return Max;
}
int main ()
{   cin>>n>>k;
    for(int i=1;i<=n;i++)
      cin>>P[i];
    for(int i=1;i<=n;i++)
      cin>>C[i];
    ll Max=-inf1;
    for(int i=1;i<=n;i++)
    {  Max=max(solve(i),Max);
	}
	ll num,numl;
	for(int i=1;i<=n;i++)
	{   if(a[i][0]<k&&a[i][a[i][0]]>0)
	    {   num=a[i][a[i][0]]*(k/a[i][0]-1);
	        Max=max(Max,num);
	        for(int j=1;j<=a[i][0];j++)
	        {   numl=num+a[i][j];
	            Max=max(Max,numl);
			}
			num+=a[i][a[i][0]];
	       for(int j=1;j<=k%a[i][0];j++)
	       {   numl=num+a[i][j];
	           Max=max(numl,Max);
		   }
		}
	}
	cout<<Max<<endl;
	return 0;
}