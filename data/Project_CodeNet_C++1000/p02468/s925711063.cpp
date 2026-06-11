#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdio>
//by NeighThorn
#define int long long
using namespace std;
const int MOD=1e9+7;
int n,m;
inline int power(int a,int b){
	int ans=1;
	while(b){
		if(b&1)
			(ans*=a)%=MOD;
		(a*=a)%=MOD;b>>=1;
	}
	return ans;
}
signed main(void){
	scanf("%lld%lld",&n,&m);
	cout<<power(n,m)<<endl;
	return 0;
}