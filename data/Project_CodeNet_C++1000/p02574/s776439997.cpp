#include<bits/stdc++.h>
#include <cstdio>
#include <algorithm>

#define maxn 1000010

using namespace std;
int a[maxn],prime[maxn],not_prime[maxn],tot,vis[maxn];
void linear_shaker(int x){
	int i,j;
	for(i=2;i<=x;i++){
		if(!not_prime[i])prime[++tot]=i;
		for(j=1;prime[j]*i<=x;j++){
			not_prime[i*prime[j]]=prime[j];
			if(i%prime[j]==0)break;
		}
	}
}
int main(){
	int n,i,m=0,b,c,cnt=0;
	scanf("%d",&n);
	for(i=1;i<=n;i++)scanf("%d",&a[i]),m=max(m,a[i]);
	linear_shaker(m);
	for(i=1;i<=n;i++){
		b=a[i];
		while(not_prime[b]){
			c=not_prime[b];
			vis[c]++,cnt=max(cnt,vis[c]);		
          while(b%c==0)b/=c;
		}
		if(b!=1)vis[b]++,cnt=max(cnt,vis[b]);
	}

  if(cnt<=1)printf("pairwise coprime\n");
	
  else if(cnt<n)printf("setwise coprime\n");
	
  else printf("not coprime\n");//cnt>=n
	
  return 0;
}
