#include <bits/stdc++.h>
#define MOD 998244353LL
using namespace std;
typedef long long ll;
typedef pair<int,int> P;

ll extgcd(ll a,ll b,ll& x,ll& y){
	ll d=a;
	if(b!=0LL){
		d=extgcd(b,a%b,y,x);
		y-=(a/b)*x;
	}else{
		x=1;
		y=0;
	}
	return d;
}

ll mod_inverse(ll a,ll m){
	ll x,y;
	extgcd(a,m,x,y);
	return (m+x%m)%m;
}

ll mod_pow(ll x,ll n){
	ll res=1;
	while(n>0){
		if(n&1){
			res=res*x%MOD;
		}
		x=x*x%MOD;
		n>>=1LL;
	}
	return res;
}


int n,s;
int a[3005];
ll dp[3005][3005];

int main(void){
	scanf("%d%d",&n,&s);
	for(int i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	ll tm=mod_inverse(2,MOD);
	dp[0][0]=mod_pow(2,n);
	for(int i=0;i<n;i++){
		for(int j=0;j<=s;j++){
			dp[i+1][j]+=dp[i][j];
			dp[i+1][j]%=MOD;
			if(j+a[i]<=s){
				dp[i+1][j+a[i]]+=dp[i][j]*tm%MOD;
				dp[i+1][j+a[i]]%=MOD;
			}
		}
	}
	printf("%lld\n",dp[n][s]);
	return 0;
}
