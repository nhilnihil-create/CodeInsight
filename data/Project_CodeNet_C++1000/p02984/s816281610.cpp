#include<bits/stdc++.h>
#define ll long long 
#define MAXN 100010
using namespace std;

int n;
ll X[MAXN];
ll m[MAXN];


int main(){
	scanf("%d",&n);
	
	int x=1;
	ll ans=0;
	for(int i=1;i<=n;i++){
		scanf("%lld",&m[i]);
		ans+=m[i]*x;
		x=-x; 
	}
	X[1]=ans/2;
	for(int i=2;i<=n;i++){
		X[i]=m[i-1]-X[i-1];
	}
	for(int i=1;i<=n;i++)printf("%lld ",2*X[i]);	
}