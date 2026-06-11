#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 110//??方式?宏是一个好?法 
int target;int a;
int test[MAX][MAX]= {0};
int length,width;
int co[4][2]= {{0,-1},{0,1},{-1,0},{1,0}};
int check(int i,int x,int y)
{
	if(((x+co[i][0])>=0&&(x+co[i][0])<length)&&((y+co[i][1])>=0&&(y+co[i][1])<width))
	return 1;
	else 
	return 0;
}
void run(int x,int y,const int style) {
	for(int i=0; i<4; i++) {
		if(check(i,x,y)) {
			if(test[x+co[i][0]][y+co[i][1]]==style) {
				if(test[x+co[i][0]][y+co[i][1]]>0)
				{
					test[x+co[i][0]][y+co[i][1]]*=-1;//火?的map233333 
					
					run(x+co[i][0],y+co[i][1],style);
				}
			} 
		}
		//如果是-1?明之前走?就不用走了，如果是2就没法走了 
	}
}
int main() {
	char str[MAX];
	scanf("%d %d",&width,&length);
	while(length!=0&&width!=0) {
		memset(&test[0][0],0,sizeof(test));
		target=0;
		for(int j=0; j<width; j++) {
			scanf("%s",str);
			for(int i=0; i<length; i++) {
				if(str[i]=='#') {
					test[i][j]=2;
				} else if(str[i]=='*') {
					test[i][j]=1;
				} else if(str[i]=='@') {
					test[i][j]=3; 
				}
			}
		}
		for(int j=0; j<width; j++) {
			for(int i=0; i<length; i++) {
				if(test[i][j]>0)
				{
					
					run(i,j,test[i][j]);//走到?就?明走完了一片 
					target++;
					//一株? 
				} 
			}
		}
		
		
		printf("%d\n",target);
		scanf("%d %d",&width,&length);//注意??? 
	}
}