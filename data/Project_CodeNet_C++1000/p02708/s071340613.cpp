#include<bits/stdc++.h>
using namespace std;

#define intt long long
#define mod 1000000007

int main()
{
	intt n,k;
	cin>>n>>k;
	intt arr[n+1];
	for(intt i=0;i<=n;i++)
	arr[i]=i;
	
	intt prefix[n+1];
	intt suffix[n+1];
	prefix[0]=arr[0];
	suffix[n]=arr[n];
	for(intt i=1;i<=n;i++)prefix[i]=prefix[i-1]+arr[i];
	for(intt i=n-1;i>=0;i--)suffix[i]=suffix[i+1]+arr[i];
	
	intt sum=0;
	for(intt j=k;j<=n+1;j++)
	{
		intt diff=suffix[n-j+1]-prefix[j-1]+1;
		sum+=(diff%mod);sum=sum%mod;
	}
	
	cout<<sum<<endl;
}
