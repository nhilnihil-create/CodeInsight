#include<iostream>
#define ll long long
using namespace std;
const ll mod=1e9+7;
ll a[2005];
int main(){
	int n;
	cin>>n;
	a[3]=1;
	for(int i=4;i<=n;i++){
		a[i]=(a[i-1]+a[i-3])%mod;
		a[i]=(a[i]+mod)%mod;
	}
	cout<<a[n]<<endl;
}