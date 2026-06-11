#include<bits/stdc++.h>
#define reg register
typedef long long ll;
using namespace std;
const int MN=1e5+5;
int n;
int main(){
	scanf("%d",&n);reg int flg=1;
	for(reg int i=3;flg&&i<=n;i+=2)
		if(n%i==0)flg=0;
	if(flg)return 0*puts("No");
	puts("Yes");
	puts("1 2");
	puts("1 3");
	printf("2 %d\n",n+3);
	printf("%d %d\n",n+3,n+1);
	printf("3 %d\n",n+2);
	for(reg int i=4;i+1<=n;i+=2){
		printf("1 %d\n",i);
		printf("1 %d\n",i+1);
		printf("%d %d\n",i,i+1+n);
		printf("%d %d\n",i+1,i+n);
	}
	if(~n&1){
		for(reg int i=2,j;i<=n;i++){
			if(i==3)continue;
			j=n^i^1;
			if(j!=3&&j<=n){
				printf("%d %d\n",i,n);
				printf("%d %d\n",j,n+n);
				break;
			}
		}
	}
	return 0;
}