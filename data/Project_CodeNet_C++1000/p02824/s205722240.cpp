#include<bits/stdc++.h>
using namespace std;
const int N=100000+10;
typedef long long ll;
int n,m,v,p;
int a[N];
ll sum[N];
int cal(int l,int r){return r-l+1;}
int check(int mid){
	if(n-mid+1<=p)return 1;
	if(a[mid]+m<a[n-p+1])return 0;
	if(p+mid-1>=v)
		return 1;
	else{
		if(cal(mid+1,n-p+1)>=v-(p+mid-1))
			return (ll)(a[mid]+m)*cal(mid+1,n-p+1)-(sum[n-p+1]-sum[mid])>=(ll)(v-(p+mid-1))*m;
		else
			return 0;
	}
}
int main(){
	cin>>n>>m>>v>>p;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)
		sum[i]=sum[i-1]+a[i];
	int l=1,r=n,ans=n;
	while(l<=r){
		int mid=(l+r)>>1;
		if(check(mid))
			ans=mid,r=mid-1;
		else
			l=mid+1;
	}
	while(ans>1&&a[ans-1]==a[ans])ans--;
	cout<<n-ans+1;
	return 0;
}