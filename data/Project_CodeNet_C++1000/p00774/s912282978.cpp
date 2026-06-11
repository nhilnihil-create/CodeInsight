#include <cstdio>
#include <cstring>
#include <climits>
using namespace std;

int h,map[10][5];
int main(){
    while(scanf("%d",&h),h){
		int ans=0;		
		for(int i=0;i<10;i++)
			for(int j=0;j<5;j++)
				if(i<h)
		 			scanf("%d",&map[h-i-1][j]);
		 		else 
		 			map[i][j]=0;
		bool boo=true;
		while(boo){
			boo=false;
			for(int z=0;z<10;z++){
			for(int i=0;i<h;i++){
				for(int j=0;j<5;j++)
					if(map[i][j]==0){
						for(int k=i+1;k<h;k++){
							map[k-1][j]=map[k][j];
							map[k][j]=0;
						}					
					}
			}
			}
			/*
			for(int i=0;i<h;i++){
				for(int j=0;j<5;j++){
					printf("%d ",map[i][j]);
				}
				printf("\n");
			}
			printf("\n");
			*/
			for(int i=0;i<h;i++){
			 	int a=-1,b=0,t=0;
			 	for(int j=0;j<5;j++){
			 		if(map[i][j]==a){
			 			t++;
			 		}else if(t<3){
			 			a=map[i][j];
			 			b=j;
			 			t=1;
			 		}else break;
			 	}
			 	
			 	if(t>=3){
			 		if(a==0)continue;
			 		boo=true;
			 		ans+=a*t;
			 		//printf("%d %d %d\n%d\n",a,b,t,ans);
			 		for(int j=0;j<t;j++)
			 			map[i][b+j]=0;
			 	}
			 }
		}
		printf("%d\n",ans);
    }
    return 0;
}