#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
	ll n;
	cin>>n;
	ll k=1;
	ll i=1;
	ll j=n;
	ll s=sqrt(n);
	//cout<<s<<endl;
	while(k<=s){
		if(n%k==0){
			i=k;
			j=n/i;
		}
		k++;
		
		
	}
	cout<<i+j-2<<endl;
}