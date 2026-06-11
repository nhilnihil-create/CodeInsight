#include<bits/stdc++.h>
using namespace std;
#define ll long long int

int main(){
	ll n;
	cin>>n;
	ll count=0,temp=1,ans=0;
	while(n%2==0){
		n/=2;
		count++;
	}
	while(count>0){
		ans++;
		count-=temp;
		temp++;
	}
	if(count<0)ans--;
	for(int i=3;i<sqrt(n);i++){
		count=0,temp=1;
		while(n%i==0){
			n/=i;
			count++;
		}
		while(count>0){
			ans++;
			count-=temp;
			temp++;
		}
		if(count<0)ans--;
	}
	if(n>2)ans++;
	cout<<ans<<endl;
	return 0;
}
