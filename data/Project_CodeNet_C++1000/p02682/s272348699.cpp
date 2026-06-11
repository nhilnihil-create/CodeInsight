#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
	ll a,b,c,k; 
	cin>>a>>b>>c>>k;
	if(a>=k)cout<<k<<endl;
	else if(a+b>=k)cout<<a<<endl;
	else{
		ll s = k-(a+b);
		cout<<a-s<<endl;
	}
}
