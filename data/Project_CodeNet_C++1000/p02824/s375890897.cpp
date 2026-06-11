#include<bits/stdc++.h>
using namespace std;
long long n,m,v,p,a[100010],lbound,ubound,ans;
bool check(long long mid){
	long long x=m+mid,num=0;
	if (a[p-1]>x) return 0;
	for (long long i=0;i<n;i++){
		if (a[i]<x||p-1==i){
			for (;i<p-1;i++) num+=m;
			for (;i<n;i++) num+=min(m,max((long long)0,x-a[i]));
			break;
		}
		num+=m;
	}
	return (num>=m*v);
}
int main(){
	cin>>n>>m>>v>>p;
	for (int i=0;i<n;i++) cin>>a[i];
	sort(a,a+n);reverse(a,a+n);
	lbound=a[n-1];ubound=a[p];
	while (lbound<ubound){
		long long mid=(lbound+ubound)/2;
		if (check(mid)==1)
			ubound=mid;
		else
			lbound=mid+1;
	}
	for (int i=lbound+100;i>=lbound-100;i--)
		if (check(i)==0){
			lbound=i+1;
			break;
		}
	for (int i=0;i<n;i++) if (a[i]>=lbound) ans++;
	cout<<ans<<endl;
	return 0;
}