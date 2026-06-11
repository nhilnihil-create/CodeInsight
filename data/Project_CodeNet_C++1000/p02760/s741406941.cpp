#include<stdio.h>
int main(){
	int arr[5][5],n;
	bool okay = false;
	for(int i = 0 ; i < 3 ; i++){
		for(int j = 0 ; j < 3 ; j++){
			scanf("%d" , &arr[i][j]);
		}
	}
	scanf("%d" , &n);
	for(int i = 0 ; i < n ; i++){
		int bingo;
		scanf("%d" , &bingo);
		for(int j = 0 ; j < 3 ; j++){
			for(int k = 0 ; k < 3 ; k++){
				if(bingo == arr[j][k]){
					arr[j][k] = -1;
				}
			}
		}		
	}
	for(int i = 0 ; i < 3 ; i++){	
		if(arr[i][0]==-1&&arr[i][1]==-1&&arr[i][2]==-1){
			okay = true;
		}
	}
	for(int i=0;i<3;++i){
    if(arr[0][i]==-1&&arr[1][i]==-1&&arr[2][i]==-1){
    	 okay=true;
		}
	}
	if(arr[0][0]==-1&&arr[1][1]==-1&&arr[2][2]==-1){
		okay=true;
	}
	if(arr[0][2]==-1&&arr[1][1]==-1&&arr[2][0]==-1){
		okay=true;
	}
	if(okay == true){
		printf("Yes\n");
	}
	else{
		printf("No\n");
	}

	return 0;
}