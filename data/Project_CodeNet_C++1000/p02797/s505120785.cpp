#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n,m,sum;
	cin>>n>>m>>sum;
	for(int i=1;i<=m;i++)
	cout<<sum<<" ";
	for(int i=1;i<=n-m;i++){
		if(sum<1e9)
	cout<<sum+1<<" ";
	    else
	   cout<<1<<" "; 
}
	cout<<endl; 
}