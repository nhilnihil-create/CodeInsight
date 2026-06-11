#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
	ll a,b,ans=0;
	cin>>a>>b;
	if(a==1){
		if(b==1)ans=1000000;
		if(b==2)ans=500000;
		if(b==3)ans=400000;
		if(b>3)ans=300000;
	}
	if(a==2){
		if(b==1)ans=500000;
		if(b==2)ans=400000;
		if(b==3)ans=300000;
		if(b>3)ans=200000;
	}
	if(a==3){
		if(b==1)ans=400000;
		if(b==2)ans=300000;
		if(b==3)ans=200000;
		if(b>3)ans=100000;
	}
	if(a>3){
		if(b==1)ans=300000;
		if(b==2)ans=200000;
		if(b==3)ans=100000;
	}
	cout<<ans;
	return 0;
}
