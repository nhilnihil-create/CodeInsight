#include<iostream>
#define AC ios_base::sync_with_stdio(0),cin.tie(0)
#define ll unsigned long long 
using namespace std;
int main(){
	AC;
	ll n,m;
	cin>>m>>n;
	if(m==1 || n==1){
		cout<<1<<"\n";
		return 0;
	}
	ll ans=0;
	ans=((m+1)/2)*((n+1)/2)+((m/2)*(n/2));
	cout<<ans<<"\n";
}