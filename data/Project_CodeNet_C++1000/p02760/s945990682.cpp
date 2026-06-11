#include<stdio.h>
// j = y
// i = x

int main(){
	int arr[4][4];
	for(int i =1;i<=3;i++){
		for(int j = 1; j<=3;j++){
			scanf("%d",&arr[i][j]);
		}
	}
	int n, input;
	bool found = false;
	scanf("%d",&n);
	int hor1=0,hor2=0,hor3=0,ver1=0,ver2=0,ver3=0,dia1=0,dia2=0;
	for(int i =1;i<=n;i++){
		scanf("%d",&input);
		
			for(int i =1;i<=3;i++){
				for(int j = 1; j<=3;j++){
					if(input == arr[i][j]){
						
						arr[i][j] = -1;
						if(i == 1){
							hor1++;
							if(j == 1){
								dia1++;
								ver1++;
							} 
							else if (j==2) ver2++;
							else if (j==3){
								dia2++;
								ver3++;
							}
						}
						
						else if(i == 2){
							hor2 ++;
							if(j == 1) ver1++;
							else if (j==2){
								dia1++;
								dia2++;
								ver2++;
							}
							else if (j==3) ver3++;
						}
						
						else if(i == 3){
							hor3 ++;
							if(j == 1){
								dia2++;
								ver1++;
							} 
							else if (j==2) ver2++;
							else if (j==3){
								dia1++;
								ver3++;
							}
						}
					}	
					if(hor1 == 3 || hor2 == 3 || hor3 == 3 || ver1 == 3 || ver2 == 3 || ver3 == 3 || dia1 == 3 || dia2 == 3){
						found = true;
						break;
					}
			} 	
		}
	}
	found?printf("Yes\n"):printf("No\n");
	
	
/*	for(int i =1;i<=3;i++){
		for(int j = 1; j<=3;j++){
			printf("%d ",arr[i][j]);=================>Check Bingo Sheet
		}
		printf("\n");
	}	*/
	
	
	
	
	
	
	return 0;
}