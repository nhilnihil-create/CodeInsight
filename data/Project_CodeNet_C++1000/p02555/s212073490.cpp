#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
const ll mod=1e9+7;
ll dp[3000]={0};
int main()
{
	ll v;
	scanf("%lld",&v);
	if(v<3){
		printf("0\n");return 0;
	}
	dp[0]=1;
	for(ll i=0;i<=v;i++){
		for(ll j=3;j+i<=v;j++){
			dp[j+i]=dp[j+i]+dp[i];
			dp[j+i]=dp[j+i]%mod;
		}
	} 
	printf("%lld\n",dp[v]);
}