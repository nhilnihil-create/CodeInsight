//Author: Fuadul Hasan(fuadul202@gmail.com)
#include<bits/stdc++.h>
using namespace std;

#define ll long long
const int N   = 2e5 + 5;

int got(int n,int x){
	return n/(1<<x);
}

int main(){
	
	ll n;
	cin>>n;
	ll cnt = 0,cnt1=  0;
	if(n&1){
		cout<<0<<endl;
		return 0;
	}
	n/=2;
	while(n){
		n /= 5;
		cnt += n;
	}

	cout<<cnt<<endl;
	

	return 0;
}