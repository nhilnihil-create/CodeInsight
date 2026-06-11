#include <stdio.h>

int main() {

	int arr[3][3]={};
	for(int i=0; i<3; i++){
		for(int j=0; j<3; j++){
			scanf("%d", &arr[i][j]);
		}
	}
	
	int n;
	scanf("%d", &n);
	int call;
	for(int k=0; k<n; k++){
		scanf("%d", &call);
		for(int i=0; i<3; i++){
			for(int j=0; j<3; j++){
			if(arr[i][j]==call){
				arr[i][j]=0;
			}
		}
			}
			
	}
	
	if(arr[0][0]==0&&arr[0][1]==0&&arr[0][2]==0 || arr[1][0]==0&&arr[1][1]==0&&arr[1][2]==0 || arr[2][0]==0&&arr[2][1]==0&&arr[2][2]==0 || arr[0][0]==0&&arr[1][0]==0&&arr[2][0]==0 || arr[0][1]==0&&arr[1][1]==0&&arr[2][1]==0 || arr[0][2]==0&&arr[1][2]==0&&arr[2][2]==0 || arr[0][0]==0&&arr[1][1]==0&&arr[2][2]==0 || arr[0][2]==0&&arr[1][1]==0&&arr[2][0]==0){
		printf("Yes\n");
	}
	else {
		printf("No\n");
	}

    return 0;
}