#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <vector>
#include <cmath>
#include <ctime>
#include <queue>
#include <set>
#include <map>
using namespace std;
int n,a[4000040],tot,vis[4000040],k1,k2,j;
int power(int x,int y){
	int base=x;
	int sum=1;
	while(y!=0){
		if(y%2==1){
			sum*=base;
		}
		base*=base;
		y/=2;
	}
	return sum;
}
bool cmp(int x,int y){
	return x>y;
}
int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	scanf("%d",&n);
	n=power(2,n);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	sort(a+1,a+n+1,cmp);
	/*
	for(int i=1;i<=n;i++){
		printf("%d ",a[i]);
	}
	printf("\n");
	*/
	vis[1]=1;
	for(int k=1;k*2<=n;k*=2){
		k1=0;
		j=1;
		for(int i=1;i<=n;i++){
			if(vis[i]==1){
				k1++;
				while(vis[j]==1||a[j]>=a[i]){
					j++;
					/*
					if(k==16){
						printf("%d ",j);
					}
					*/
					if(j>n){
						printf("No\n");
						return 0;
					}
				}
				vis[j]=2;
				j++;
				if(j>n&&k1<k){
					printf("No\n");
					return 0;
				}
			}
			if(k1==k){
				break;
			}
		}
		/*
		printf("\nk : %d\n",k);
		for(int i=1;i<=n;i++){
			printf("%d ",vis[i]);
		}
		printf("\n");
		*/
		for(int i=1;i<=n;i++)
			if(vis[i]==2) vis[i]=1;
	}
	printf("Yes\n");
	return 0;
}