#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef long double ld;
#define rep(i,n) for(int i=0;i<(n);i++)
#define init(a,i) for(int k=0;k<(i);k++)(a)[k]=0
#define in(a,i) for(int k=0;k<(i);k++)cin>>(a)[k]
ll nC2(ll n){
	return n*(n-1)/2;
}
	
int main(){
	ll n;
	cin>>n;
	ll a[n],b[n+1];
	in(a,n);
	memcpy(b,a,n*sizeof(ll));
	sort(b,b+n);
	ll sum=0;
	ll count=0;
	b[n]=200001;
	rep(i,n){
		if(b[i]==b[i+1])count++;
		else{
			count++;
			sum+=nC2(count);
			count=0;
		}
	}
	rep(i,n){
		count=upper_bound(b,b+1+n,a[i])-lower_bound(b,b+1+n,a[i]);
		cout<<sum+nC2(count-1)-nC2(count)<<"\n";
	}
	return 0;
}