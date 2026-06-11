#include <bits/stdc++.h>
#define MOD 1000000007LL
using namespace std;
typedef long long ll;
typedef pair<int,int> P;

int n;
bool used[300005];

void solve(){
	for(int i=0;i<n*2-1;i++){
		printf("%d %d\n",i+1,i+2);
	}
}

void solve2(int v){
	printf("%d %d\n",1,2);
	printf("%d %d\n",2,3);
	printf("%d %d\n",3,n+1);
	printf("%d %d\n",n+1,n+2);
	printf("%d %d\n",n+2,n+3);
	for(int i=4;i<n;i+=2){
		printf("%d %d\n",n+1,i);
		printf("%d %d\n",i,i+1);
		printf("%d %d\n",n+1,n+i+1);
		printf("%d %d\n",n+i+1,n+i);
	}
	if(n%2==0){
		for(int i=1;i<=n-1;i++){
			if((n^i^1)<n){
				if(i==1){
					printf("%d %d\n",n+1,n);
				}else if(i==2){
					printf("%d %d\n",n+2,n);
				}else if(i==3){
					printf("%d %d\n",3,n);
				}else if(i%2==0){
					printf("%d %d\n",i,n);
				}else{
					printf("%d %d\n",n+i,n);
				}
				i=(n^i^1);
				if(i==1){
					printf("%d %d\n",n+1,n*2);
				}else if(i==2){
					printf("%d %d\n",n+2,n*2);
				}else if(i==3){
					printf("%d %d\n",3,n*2);
				}else if(i%2==0){
					printf("%d %d\n",i,n*2);
				}else{
					printf("%d %d\n",n+i,n*2);
				}
				break;
			}
		}
	}
}

int main(void){
	scanf("%d",&n);
	if(n<=2){
		printf("No\n");
	}else{
		int v=4;
		while(v<=n+1){
			if(v==(n+1)){
				printf("Yes\n");
				solve();
				return 0;
			}
			if(v==n){
				printf("No\n");
				return 0;
			}
			v*=2;
		}
		printf("Yes\n");
		v/=2;
		solve2(v);
	}
	return 0;
} 