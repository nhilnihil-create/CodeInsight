#include<bits/stdc++.h>
#define ll long long int
#define l(i,a,b) for(ll i=a;i<b;i++)
using namespace std;
int main(){
	ll a,b,n;
	cin>>a>>b>>n;
	ll value = min(b-1,n);
	
	double num = (double)(a*value/b);
	cout<<(ll)floor(num)<<"\n";
	
	
}