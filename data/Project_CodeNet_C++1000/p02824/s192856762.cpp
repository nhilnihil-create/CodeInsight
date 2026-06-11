#include<bits/stdc++.h>

using namespace std;
long long a[100005];
long long n,m,v,p;
bool check(int x){
	if(x<=p)return true;
	if(a[x]+m<a[p])return false;
	long long can=0;
	can+=m*(p-1);
	can+=m*(n-x+1);
	for(int i=p;i<x;i++){
		can+=(a[x]+m-a[i]);
	}
    if(can>=m*v)return true;
	return false;
}
int main(){
	cin>>n>>m>>v>>p;
	long long l=0,r=n+1;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	reverse(a+1,a+n+1);
	while(l+1<r){
		long long mid=(l+r)/2;
		if(check(mid))l=mid;
		else r=mid;
	}
	long long ans=0;
	for(int i=1;i<=n;i++){
		if(a[i]>=a[l])ans++;
	}
	cout<<ans<<endl;
	return 0;
}