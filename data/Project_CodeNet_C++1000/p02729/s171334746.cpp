#include<stdio.h>
int main(){
	int N; int x=0;
	int M; int y=0;
		scanf("%d %d",&N,&M);
		int i;
		
			if(N+M!=2){
				for(i=0;i<N;i++)
					x+=i;
				for(i=0;i<M;i++){
					y+=i;	
					}
					printf("%d\n",x+y);
				}
			else{
				puts("0");
			}
			return 0;
			}
	