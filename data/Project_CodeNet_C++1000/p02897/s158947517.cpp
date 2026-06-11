#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
	ll n;
	cin>>n;
	ll odd=0,even=0;
for(ll i=1;i<=n;i++){
	if(i%2!=0){
		odd++;
	}
	else{
		even++;
	}
}
double t=double(odd)/double(n);
cout<<t;
	
	return 0;
}