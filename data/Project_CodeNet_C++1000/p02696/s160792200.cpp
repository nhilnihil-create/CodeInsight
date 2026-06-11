#include<bits/stdc++.h>
#define inf 0x3f3f3f3f
using namespace std;
typedef long long ll;



int main(){
	ll a,b,n;
	cin>>a>>b>>n;
	ll flag=-inf;

	if(n < b){
		cout<<(a*n)/b<<endl;
		return 0;
	} 
	else{
		flag = max(a*(b-1)/b,flag);
		flag = max(flag,(a*n)/b-a*(n/b));
	}
	cout<<flag<<endl;
	return 0;
}