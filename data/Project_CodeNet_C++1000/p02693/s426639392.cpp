#include<bits/stdc++.h>
#define ll long long int
#define l(i,a,b) for(ll i=a;i<b;i++)
using namespace std;
int main(){
	ll n,a,b,calc=0;
	cin>>n>>a>>b;
	calc = b/n;
	calc*=n;
	if(a<=calc) cout<<"OK\n";
	else cout<<"NG\n";
}