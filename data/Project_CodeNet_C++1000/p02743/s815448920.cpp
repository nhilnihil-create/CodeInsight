#include<iostream>
#define AC ios_base::sync_with_stdio(0),cin.tie(0)
#define ll long long 
#define eps 1e-6
using namespace std;
int main(){
	AC;
	ll a,b,c;
	cin>>a>>b>>c;
	ll p=(c-a-b)*(c-a-b);
	if(c-a-b<=2) cout<<"No\n";
	else if(4*a*b<p) cout<<"Yes\n";
	else cout<<"No\n";
}
