#include<bits/stdc++.h>
using namespace std;

long long lcd(long long a,long long b){
	if(a<b) swap(a,b);
	while(b){
		long long t = a%b;
		a = b;
		b = t;
	}
	return a;
}
long long f(long long a,long long b){
	return a*b/lcd(a,b);
}
int main(){
	long long n,m;
	cin>>n>>m;
	vector<long long>arr(n);
	for(int i=0; i<n; i++){
		cin>>arr[i];
		arr[i]/=2;
	}
	long long LCM = arr[0];
	for(int i=1; i<n; i++) LCM = f(LCM,arr[i]);
	bool qualified = true;
	for(int i=0; i<n; i++){
		if((LCM/arr[i])%2==0) qualified = false;
	}
	if(!qualified) cout<<0;
	else{
		long long ret = m/LCM;
		if(ret%2) cout<<ret/2+1;
		else cout<<ret/2;
	}
}