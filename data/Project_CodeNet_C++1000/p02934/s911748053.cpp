#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
#define ll long long
int main(){
	ll n; cin>>n;
	ll t;
	double x=0;
	for(int i=0;i<n;i++) cin>>t,x+=1.0/(double)t;
	x=1.0/x;
	cout<<fixed<<setprecision(12)<<x;

}
