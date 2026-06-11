#include<bits/stdc++.h>
using namespace std;
const long long N=2e3+10;
const long long MOD=1e9+7;
long long a[N];
long long s,ans;
int main(){
	scanf("%lld",&s);
	a[3]=1;
	for(int i=4;i<=s;i++)
		a[i]=(a[i-1]%MOD+a[i-3]%MOD)%MOD;
	printf("%lld",a[s]);
	return 0;
}