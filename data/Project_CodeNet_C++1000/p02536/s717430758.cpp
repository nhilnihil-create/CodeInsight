#include<iostream>
#include<stdio.h>
#include<cstring>
#define int long long
#define max(a,b) (a>b)?a:b
using namespace std;
const int N=1e6+10;
int f[N];
int find(int k){
	if(f[k]==k)	{
		return k;
	}else{
		return f[k]=find(f[k]);
	}
}
int n,m;
bool c[N];
signed main(){
	scanf("%lld %lld ",&n,&m);
	for(int i=1;i<=n;i++)
		f[i]=i;
	for(int a,b,i=1;i<=m;i++){
		scanf("%lld %lld",&a,&b);
		f[find(a)]=find(b);
	}
	int ans=0;
	for(int i=1;i<=n;i++){
		if(!c[find(i)]){
			c[find(i)]=1;
			ans++;
		}
	}
	printf("%lld \n",(max(ans-1,(int)0)));
}


