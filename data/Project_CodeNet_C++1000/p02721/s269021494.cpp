#include<bits/stdc++.h>
using namespace std;
const int N=2e5+9;
int n,k,c;int tot,tot1,ans,a[N],b[N],g[N]; int rest;
char s[N];
int main(){
	cin>>n>>k>>c>>s+1;
	rest=0;
	for(int i=1;i<=n;i++){
		if(s[i]=='o'&&rest<=0) a[++tot]=i,rest=c;
		else rest--;
	}
	rest=0;
	for(int i=n;i>=1;i--){
		if(s[i]=='o'&&rest<=0) b[++tot1]=i,rest=c;
		else rest--;
	}
	for(int i=1;i<=tot1/2;i++) swap(b[i],b[tot1-i+1]);
	//for(int i=1;i<=tot;i++) cout<<a[i]<<" ";
	for(int i=1;i<=min(tot,tot1);i++)
		if(a[i]==b[i]) g[++ans]=a[i];
	if(ans<=k) for(int i=1;i<=ans;i++) printf("%lld\n",g[i]);
	return 0;
}