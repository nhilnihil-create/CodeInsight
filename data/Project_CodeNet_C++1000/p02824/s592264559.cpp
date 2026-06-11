#include<bits/stdc++.h>
using namespace std;
long long n,m,v,p,a[100010];
bool check(int x){
	long long cnt=0;
	if(a[x]+m<a[p-1])
		return 0;
	cnt+=(p-1)*m+(n-x)*m;
	for(int i=p-1;i<x;i++)
		cnt+=a[x]+m-a[i];
	return (cnt>=m*v);
}
int main(){
	cin>>n>>m>>v>>p;
	for(int i=0;i<n;i++)
		cin>>a[i];
	sort(a,a+n);
	reverse(a,a+n);
	long long l=0,r=n-1,mid;
	while(l<=r){
		mid=(l+r)/2;
		if(check(mid))
			l=mid+1;
		else
			r=mid-1;
	}
	cout<<l;
	return 0;
}