#include<bits/stdc++.h>
using namespace std;
const int N=1e6;
int p[N/2];
bool vis[N+10];
int f[N+10];
int main(){
	int m=0;
	for(int i=2;i<=N;i++){
		if(!vis[i])p[++m]=i,f[i]=i;
		for(int j=1;j<=m&&p[j]*i<=N;j++){
			vis[p[j]*i]=true;
			f[p[j]*i]=p[j];
			if(i%p[j]==0)break;
		}
	}
	int n;
	cin>>n;
	bool pa=true;
	int d=0;
	for(int i=1;i<=n;i++){
		int a;
		cin>>a;
		d=__gcd(d,a);
		while(a>1){
			int j=f[a];
			if(vis[j])pa=false;
			vis[j]=true;
			for(a/=j;a%j==0;a/=j);
		}
	}
	puts(pa?"pairwise coprime":(d==1)?"setwise coprime":"not coprime");
}