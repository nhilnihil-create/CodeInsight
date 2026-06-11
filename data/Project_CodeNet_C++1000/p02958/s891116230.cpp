#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
#define ll long long
int main(){
	ll n; cin>>n;
	ll a[n],d=0;
	for(int i=0;i<n;i++){
		cin>>a[i];
		if(i+1!=a[i]) d++;
	}
	if(d<3) cout<<"YES";
	else cout<<"NO";
}
