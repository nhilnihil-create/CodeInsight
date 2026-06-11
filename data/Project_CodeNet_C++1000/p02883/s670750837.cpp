//============================================================================
// Name        : e.cpp
// Author      :
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;
typedef long long ll;
int main() {
	int n;cin>>n;
	ll k;cin>>k;
	vector<ll> a(n),f(n);
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(int i=0;i<n;i++){
		cin>>f[i];
	}
	sort(a.begin(),a.end());
	sort(f.begin(),f.end());
	reverse(f.begin(),f.end());
	ll r=a[n-1]*f[0];
	ll l=-1;
	while(r!=l+1){
		ll temp=(r+l)/2;
		ll needk=0;
		for(int i=0;i<n;i++){
			if(a[i]*f[i]>temp){
				needk+=(a[i]*f[i]-temp-1)/f[i]+1;
			}
		}
		if(needk<=k){
			r=temp;
		}else{
			l=temp;
		}
//		cout<<l<<' '<<r<<endl;
	}
	cout<<r<<endl;
	return 0;
}
