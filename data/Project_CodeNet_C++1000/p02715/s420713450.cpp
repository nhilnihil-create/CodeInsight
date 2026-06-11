#include<iostream>
#include<cmath>
#include<map>
#include<set>
#include<vector>
#include<algorithm>
#include<iomanip>
using namespace std;
#define mod 1000000007
#define int long long int
int power(int a,int b)
{
	if(b==0)
	  return 1;
	int r=power(a,b/2);
	if(b%2==0)
	{
		return (r*r)%mod;
	}
	else
	{
		int x=(r*r)%mod;
		return (a*x)%mod;
	}
}
int32_t main()
{
	int n,k;
	cin>>n>>k;
	int arr[k+1];
	int j;
	for(j=k;j>=1;j--)
	{
		int total=k/j;
		int sub=power(total,n);
		int i;
		for(i=2;i*j<=k;i++)
		{
			sub-=arr[i*j];
			sub=sub%mod;
		}
		arr[j]=sub;
	}
	int answer=0;
	for(j=1;j<=k;j++)
	{
		answer=answer+j*arr[j];
		answer=answer%mod;
	}
	if(answer<=0)
	  answer+=mod;
	cout<<answer<<endl;
}
