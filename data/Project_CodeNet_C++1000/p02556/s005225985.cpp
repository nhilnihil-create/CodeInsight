#include<bits/stdc++.h>

#define all(x) x.begin(),x.end()

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const long long MOD=1e9+7;
const long long LINF=1e18;
const int INF=0x3f3f3f3f;
const int MAXN=200050;

void solve(int T){
	int n;
	int max1,min1,max2,min2;
	max1=max2=-INF;
	min1=min2=INF;
	scanf("%d",&n);
	int x,y;
	for(int i=1;i<=n;i++){
		scanf("%d %d",&x,&y);
		max1=max(max1,x+y);
		min1=min(min1,x+y);
		max2=max(max2,x-y);
		min2=min(min2,x-y);
	}
	printf("%d\n",max(max1-min1,max2-min2));
}
signed main(){
	int t=1;
	//ios::sync_with_stdio(false);
	//cin.tie(0);
	//scanf("%d",&t); 
	for(int i=1;i<=t;i++){
		solve(i);
	}
}