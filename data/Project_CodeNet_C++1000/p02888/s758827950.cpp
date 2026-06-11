#include<bits/stdc++.h>
#define ll long long 
#define MAXN 200010
using namespace std;

int n,m;
int X[2010];

int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&X[i]);
	}
	sort(X+1,X+1+n);
	
	ll ans=0;
	for(int i=1;i<=n-2;i++){
		for(int j=i+1;j<=n-1;j++){
			int x=lower_bound(X+j+1,X+n+1,X[i]+X[j])-X;
		//	if(x>n)continue;
			ans+=x-1-j;
		}
	}
	printf("%lld",ans);
}
