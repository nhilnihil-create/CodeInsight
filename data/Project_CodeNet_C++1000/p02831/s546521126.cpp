//Author: Fuadul Hasan(fuadul202@gmail.com)
#include<bits/stdc++.h>
using namespace std;

#define ll long long
const int N   = 2e5 + 5;

long long Lcm(long long a,long long b){
	return (((a)*(b)))/__gcd(a,b);
}

int main(){
	
	ll a,b;
	cin>>a>>b;


	cout<<Lcm(a,b)<<endl;	


	
	
	return 0;
}