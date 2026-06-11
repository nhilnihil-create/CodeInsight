#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <set>
#include <stdio.h>
#include <math.h>
#include <queue>
using namespace std;
typedef long long int lli;
const long long int MaxN=200004;
const lli mod=1e9+7;
#define fst first
#define snd second
#define mp make_pair
const float pi=3.1415926535897932384626433832795028;
	lli mcd(lli a,lli b){
		if(a==0)return b;
		return mcd(b%a,a);
	}
	lli dp[MaxN];
	lli nel[MaxN];
	void solve(){
		lli N,M,i,j,p;
		cin>>N>>M;
		for(i=0;i<M;i++){
			cin>>p;
			nel[p]=1;
		}
		dp[0]=1;
		for(i=1;i<=N;i++){
			if(!nel[i-1])dp[i]+=dp[i-1];
			if(!nel[i-2]&&i>1)dp[i]+=dp[i-2];
			//cout<<dp[i]<<" "<<i<<"\n";
			dp[i]=dp[i]%mod;
		}
		cout<<dp[N];
	}
int main(){
	cin.tie(0),ios_base::sync_with_stdio(0);
	lli i,j,t;
	t=1;
	for(i=1;i<=t;i++){
		solve();
	}
}
