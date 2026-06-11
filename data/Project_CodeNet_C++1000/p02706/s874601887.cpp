#include<bits/stdc++.h>
#define ll long long int
#define l(i,a,b) for(ll i=a;i<b;i++)
#define PI 3.14159265358979323846
using namespace std;
int main(){
	ll n,m,sum=0;
	cin>>n>>m;
	ll a[m];
	l(i,0,m) cin>>a[i],sum+=a[i];
	if(sum>n) cout<<-1<<"\n";
	else{
		cout<<n-sum<<"\n";
	}
}