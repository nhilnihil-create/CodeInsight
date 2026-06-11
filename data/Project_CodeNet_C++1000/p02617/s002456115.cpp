#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e5+5,M=1e6+5,inf=0x3f3f3f3f,mod=1e9+7;
#define mst(a) memset(a,0,sizeof a)
#define lx x<<1
#define rx x<<1|1
#define reg register
#define PII pair<int,int>
#define fi first 
#define se second
int main(){
	int n;
	scanf("%d",&n);
	ll ans=1LL*n*(n+1)*(n+2)/6;
	for(int i=1;i<n;i++){
		int u,v;
		scanf("%d%d",&u,&v);
		if(u>v) swap(u,v);
		ans-=1LL*u*(n-v+1); 
	}
	printf("%lld\n",ans); 
	return 0;
}