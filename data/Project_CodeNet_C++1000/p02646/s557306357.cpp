#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main() {
	// your code goes here
	ll a,v;
	cin>>a>>v;
	ll b,w;
	cin>>b>>w;
	ll t;
	cin>>t;
	ll d_a=v*t;
	ll d_b=w*t;
	ll d_btw=abs(b-a);
	if(d_b+d_btw<=d_a || a==b){
		cout<<"YES"<<endl;
	}
	else{
		cout<<"NO"<<endl;
	}
	return 0;
}