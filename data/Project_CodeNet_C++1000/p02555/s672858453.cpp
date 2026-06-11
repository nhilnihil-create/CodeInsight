#include<iostream>
using namespace std;
typedef long long int ll;
const int maxn=2e5+10;
const int mod=1e9+7;
ll a[maxn];
int main(){
	a[1]=0;
	a[2]=0;
	a[3]=1;
	for(int i=4;i<maxn;i++){
		a[i]=(a[i-1]+a[i-3])%mod;
	}
	int n;
	cin>>n;
	cout<<a[n]<<endl;
}