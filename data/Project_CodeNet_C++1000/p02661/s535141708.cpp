#include<bits/stdc++.h>
using namespace std;
using ll = long long;
ll a[200005],b[200005];
int main(){
	ll n;
	cin>>n;
	for(ll i=0;i<n;i++){
		scanf("%lld%lld",&a[i],&b[i]);
	}
	sort(a,a+n);
	sort(b,b+n);
	ll low ,hi;
	if(n&1){
		low = a[(n-1)/2];
		hi = b[(n-1)/2];
	}else{
		low = a[(n-2)/2] + a[(n-2)/2+1] ;
		hi = b[(n-2)/2] + b[(n-2)/2+1];
	}
	cout<<hi-low+1<<endl;
	return 0;
}