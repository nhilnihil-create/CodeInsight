#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n,k,q,w,s=0;
	cin>>n>>k;
	int a,b,c[n+1]={0};
	for(q=1;q<=k;q++)
	{
		cin>>a;
		for(w=1;w<=a;w++){
			cin>>b;
			c[b]=1;
		}	
	}
	for(q=1;q<=n;q++)
	{
		if(c[q]==0)  s++;
	}
	cout<<s;
}