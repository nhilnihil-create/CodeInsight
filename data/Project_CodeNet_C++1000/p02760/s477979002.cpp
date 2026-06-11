#include<stdio.h>
int main(){
	int arr[3][3];
	int tc;
	int add;
	int check[3][3]= {0};
	int count;
	int i,j;
	for(i=0;i<3;i++){
		for(j=0;j<3;j++){
			scanf("%d", &arr[i][j]);
		}
	}
	scanf("%d",&tc);
	int k;
	
	for(k=0;k<tc;k++){
		scanf("%d",&add);
		int j;
		for(i=0;i<3;i++){
			for(j=0;j<3;j++){
				if(arr[i][j]== add){
					check[i][j] = 1;
				}
			}
		}
	}
	if(check[0][0]+ check [1][1]+ check[2][2]== 3 || check [0][2]+check [1][1]+ check[2][0]==3){
		printf("Yes\n");
		return 0;
	}
	for(i=0;i<3;i++){
		if(check[i][0]+check[i][1]+check[i][2]==3 || check [0][i]+check[1][i]+check[2][i]==3){
			printf("Yes\n");
			return 0;
		}
	}
	printf("No\n");
	
	return 0;
}