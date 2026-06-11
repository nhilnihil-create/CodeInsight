#include<bits/stdc++.h>
using namespace std;
int a[111];
bool used[111];
int main()
{
	int x,n;
	cin>>x>>n;
	for(int i=0;i<n;i++){ 
		cin>>a[i];
		used[a[i]]=true;
	} 
	int ans=x;
	for(int i=1;i<x+ans;i++)
		if(!used[i])
			ans=min(ans,x-i);
	cout<<x-ans<<endl;
	return 0;
}