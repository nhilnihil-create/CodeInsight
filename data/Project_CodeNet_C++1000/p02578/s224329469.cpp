#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
	ll n;
	cin>>n;
	vector<int> a(n);
	if(n==0){
	cout<<"0";return 0;
	}
	for(int i=0;i<n;i++)cin>>a[i];
	ll m=a[0],c=0;
	for(int i=0;i<n;i++){
		if(a[i]>=m){
		m=a[i];}
		
		else{
			c+=m-a[i];
		}
	}
	cout<<c;
}