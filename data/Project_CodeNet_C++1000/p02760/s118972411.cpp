#include <stdio.h>

int main(){
    
    int arr[3][3];
    int arr1[3][3] = {};
    int n;
    
    for(int i = 0 ; i < 3 ; i++){
    	for(int j = 0 ; j < 3 ; j++){
    		scanf("%d", &arr[i][j]);
		}
	}
    
    scanf("%d", &n);
    int b[n];
    for(int i = 0 ; i < n ; i++){
    	scanf("%d", &b[i]);
	}
	
	for(int i = 0 ; i < n ; i++){
		if(b[i] == arr[0][0]){
			arr1[0][0] += 1;
			continue;
		}
		if(b[i] == arr[0][1]){
			arr1[0][1] += 1;
			continue;
		}
		if(b[i] == arr[0][2]){
			arr1[0][2] += 1;
			continue;
		}
		if(b[i] == arr[1][0]){
			arr1[1][0] += 1;
			continue;
		}
		if(b[i] == arr[1][1]){
			arr1[1][1] += 1;
			continue;
		}
		if(b[i] == arr[1][2]){
			arr1[1][2] += 1;
			continue;
		}
		if(b[i] == arr[2][0]){
			arr1[2][0] += 1;
			continue;
		}
		if(b[i] == arr[2][1]){
			arr1[2][1] += 1;
			continue;
		}
		if(b[i] == arr[2][2]){
			arr1[2][2] += 1;
			continue;
		}
	}
    
    if(arr1[0][0] > 0 && arr1[0][1] > 0 && arr1[0][2] > 0){
    	printf("Yes\n");
    	return 0;
	}
	if(arr1[0][0] > 0 && arr1[1][1] > 0 && arr1[2][2] > 0){
    	printf("Yes\n");
    	return 0;
	}
	if(arr1[1][0] > 0 && arr1[1][1] > 0 && arr1[1][2] > 0){
    	printf("Yes\n");
    	return 0;
	}
	if(arr1[2][0] > 0 && arr1[2][1] > 0 && arr1[2][2] > 0){
    	printf("Yes\n");
    	return 0;
	}
	if(arr1[0][0] > 0 && arr1[1][0] > 0 && arr1[2][0] > 0){
    	printf("Yes\n");
    	return 0;
	}
	if(arr1[0][1] > 0 && arr1[1][1] > 0 && arr1[2][1] > 0){
    	printf("Yes\n");
    	return 0;
	}
	if(arr1[0][2] > 0 && arr1[1][2] > 0 && arr1[2][2] > 0){
    	printf("Yes\n");
    	return 0;
	}
	if(arr1[0][2] > 0 && arr1[1][1] > 0 && arr1[2][0] > 0){
    	printf("Yes\n");
    	return 0;
	}
	printf("No\n");
    
    return 0;
}