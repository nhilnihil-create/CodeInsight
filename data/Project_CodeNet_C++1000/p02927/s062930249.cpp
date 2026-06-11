#include <stdio.h>
int m,d;
int ans;
int main(){
	scanf("%d %d",&m,&d);
	for(int i=1;i<=m;i++){
		for(int j=10;j<=d;j++){
			if((j/10)>1&&(j%10)>1&&(j/10)*(j%10)==i){
				ans++;
			}
		}
	}
	printf("%d\n",ans);
}