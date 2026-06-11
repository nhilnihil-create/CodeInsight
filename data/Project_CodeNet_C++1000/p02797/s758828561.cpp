#include<bits/stdc++.h>
using namespace std;
int a[114514];
int main(){
	int n,k,s;
	cin>>n>>k>>s;
	for(int i=1;i<=k;++i) a[i]=s;
	for(int i=k+1;i<=n;++i) a[i]=(s==1e9?s-1:s+1);
	for(int i=1;i<=n;++i)cout<<a[i]<<" ";
	return 0;
}