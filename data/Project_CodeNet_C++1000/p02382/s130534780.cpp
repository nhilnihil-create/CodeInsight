#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

long double cbrt(ll a){
	long double left=0,right=INT_MAX;
	for(int i=0;i<1000;i++){
		long double med=(left+right)/2.0;
		long double cal=med*med*med;
		if(cal<a)	left=med;
		else 	right=med;
	}
	return left;
}
long double sqrt(ll a){
	long double left=0,right=INT_MAX;
	for(int i=0;i<1000;i++){
		long double med=(left+right)/2.0;
		long double cal=med*med;
		if(cal<a)	left=med;
		else 	right=med;
	}
	return left;
}
int main(){
	int n;	cin>>n;
	vector<ll> x(n),y(n);
	for(int i=0;i<n;i++)	cin>>x[i];
	for(int i=0;i<n;i++)	cin>>y[i];
	ll d1=0,d2=0,d3=0,d4=0;
	for(int i=0;i<n;i++){
		d1+=abs(x[i]-y[i]);
		d2+=(x[i]-y[i])*(x[i]-y[i]);
		d3+=abs(x[i]-y[i])*(x[i]-y[i])*(x[i]-y[i]);
		d4=max(d4,abs(x[i]-y[i]));
	}
	printf("%lld\n",d1);
	printf("%.15Lf\n",sqrt(d2));
	printf("%.15Lf\n",cbrt(d3));
	printf("%lld\n",d4);
	return 0;
}
	