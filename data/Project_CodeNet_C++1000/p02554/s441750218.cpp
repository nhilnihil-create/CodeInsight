#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
const int mod=1e9+7;
inline int ksm(int a,int b){
	int res=1;
	while (b){
		if (b&1) res=1ll*res*a%mod;
		a=1ll*a*a%mod;b>>=1;
	}
	return res;
}
int main(){
	int n;cin>>n;
	cout<<(ksm(10,n)-2ll*ksm(9,n)%mod+ksm(8,n)%mod+mod)%mod;
	return 0;
}