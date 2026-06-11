#include<stdio.h>
int main()
{
	int a[3][3],n,b[10];
	int i,j,k,x[3][3]={0},f=0;
	for(i=0;i<3;i++){
		for(j=0;j<3;j++){
			scanf("%d",&a[i][j]);
		}
	}
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%d",&b[i]);
	}
	for(i=0;i<3;i++){
		for(j=0;j<3;j++){
			for(k=0;k<n;k++){
				if(a[i][j]==b[k]){
					x[i][j]=1;
				}
			}
		}
	}
	for(i=0;i<3;i++){
		if(x[0][i]==1&&x[0][i]==x[1][i]&&x[2][i]==x[0][i]){
			f=1;
		}
		if(x[i][0]==1&&x[i][0]==x[i][1]&&x[i][2]==x[i][0]){
			f=1;
		}
	}
	if(x[0][0]==1&&x[0][0]==x[1][1]&&x[0][0]==x[2][2]){
		f=1;
	}
	if(x[0][2]==1&&x[0][2]==x[1][1]&&x[0][2]==x[2][0]){
		f=1;
	}
	if(f==1){
		printf("Yes\n");
	}
	else{
		printf("No\n");
	}
	return 0;
}
