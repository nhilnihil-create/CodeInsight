#include<bits/stdc++.h>
using namespace std;
const int MAXN=0x3f3f3f;  
int a[105];
int n,i,j,k,minv=MAXN,ans;
int main(){
	cin>>n;
	for(i=1;i<=n;i++)
	cin>>a[i];
	sort(a+1,a+n+1); 
	for(i=a[1];i<=a[n];i++){ 
		for(k=1;k<=n;k++)  
		ans+=(a[k]-i)*(a[k]-i);
		minv=min(minv,ans);
		ans=0; 
	}
	cout<<minv;
	return 0;
}