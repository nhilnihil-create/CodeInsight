#include<bits/stdc++.h>

#define all(x) x.begin(),x.end()

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const ll MOD=1e9+7;
const ll LINF=1e18;
const int INF=0x3f3f3f3f;
const int MAXN=100050;

void solve(int T){
	ll s,x1,x2,y1,y2;
	scanf("%lld",&s);
	if(s<=1e9){
		printf("0 0 1 0 0 %lld\n",s);
		return;
	}
	if(s==1e18){
		printf("0 0 0 1000000000 1000000000 0\n");
		return;
	}
	x1=1000000000;
	y2=s/1000000000+1;
	ll sy=s-s/1000000000*1000000000;
	x2=1000000000-sy;
	y1=1;
	printf("0 0 %lld %lld %lld %lld\n",x1,y1,x2,y2);
}
signed main(){
	int t=1;
	//scanf("%d",&t); 
	for(int i=1;i<=t;i++){
		solve(i);
	}
}