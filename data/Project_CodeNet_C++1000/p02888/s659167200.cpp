#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
const int MAXN=2010;
int n;
int L[MAXN];
int coo(int x,int y)
{
	if(x<y)  return 1;
	return 0;
}
int main()
{
	cin>>n;
	for(int i=0;i<n;i++)  cin>>L[i];
	sort(L,L+n,coo);
	int k;
	long long ans=0;
	for(int i=0;i<n-2;i++)
	{
		for(int j=i+1;j<n-1;j++)
		{
			k=L[i]+L[j];
			int p=lower_bound(L+j+1,L+n,k)-L;
			ans+=p-j-1;
		}
	}
	cout<<ans<<endl;
	return 0;
}