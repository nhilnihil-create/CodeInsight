#include <bits/stdc++.h>
#define rep(I,N) for(int I=0;I<N;I++)
using ll=long long int;
using namespace std;

ll k,n;
int main(){
	cin>>k>>n;
	ll a[n];
	rep(i,n){
		cin>>a[i];
	}
	ll max=0;
	rep(i,n-1)if(max<a[i+1]-a[i])max=a[i+1]-a[i];
	if(max<(k-a[n-1]+a[0]))max=k-a[n-1]+a[0];


	cout<<k-max<<endl;
}
