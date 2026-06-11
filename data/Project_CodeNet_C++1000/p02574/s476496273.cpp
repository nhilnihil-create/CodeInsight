#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
int prime[N],vis[N],n,cnt,a[N];
inline void init(){
	int m=(int)sqrt(N+0.5);
	for(int i=2;i<=m;i++){
		if(vis[i]==0){
			for(int j=i*i;j<=1000000;j+=i){
				vis[j]=1;
			}
		}
	}
	for(int i=2;i<=1000000;i++){
		if(vis[i]==0)prime[++cnt]=i;
	}
}
bool pairwise(){
	set<int>t;
	for(int i=1;i<=n;i++){
		int x=a[i];
		for(int j=1;pow(prime[j],2)<=x;j++){
			if(x%prime[j]==0){
				if(t.count(prime[j]))return 0;
				t.insert(prime[j]);
				while(x%prime[j]==0){
					x/=prime[j];
				}
			}
		}
		if(x>1){
			if(t.count(x))return 0;
			t.insert(x);
		}
	}
	return  1;
}
bool setwise(){
	int x=a[1];
	for(int i=2;i<=n;i++)x=__gcd(x,a[i]);
	return x==1;
}
int main(){
	init();
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	scanf("%d",&a[i]);
	if(pairwise())printf("pairwise coprime\n");
	else if(setwise())printf("setwise coprime\n");
	else printf("not coprime\n");
}