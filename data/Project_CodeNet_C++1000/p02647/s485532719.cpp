#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int ll
int32_t main()
{
	int n,k,l,r;
	cin>>n>>k;
	int a[n];
	int b[n];
	for(auto &i:a)cin>>i;
	int t[n];
	bool eq;
	for(int i=0;i<n;i++)t[i]=n;
	while(k--)
	{
		eq=1;
		for(int i=0;i<n;i++)b[i]=0;
		for(int i=0;i<n;i++)
		{
			l=max(0LL,i-a[i]);
			r=min(n-1,i+a[i]);
			b[l]++;
			if(r+1<n)b[r+1]--;
		}
		
		for(int i=1;i<n;i++)
		{b[i]+=b[i-1];}
		for(int i=0;i<n;i++)
		a[i]=b[i];
		
		for(int i=0;i<n;i++)
		{if(a[i]!=t[i]){eq=0;break;}}
		if(eq)break;
	}
	for(auto i:a)cout<<i<<" ";
}