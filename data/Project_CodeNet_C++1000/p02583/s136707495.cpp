#include <stdio.h>

int main(){
	int n;
	long long int arr[105];
	long long int temp = 0;
	int ctr =  0;
	scanf("%d", &n);
	for(int i = 0; i < n;i++){
		scanf("%lld", &arr[i]);
	}
	for(int j = 0;j < n - 1;j++){
		for(int k = 0;k < n - j - 1;k++){
			if(arr[k] > arr[k+1]){
				temp = arr[k];
				arr[k] = arr[k+1];
				arr[k+1] = temp;
			}
		}
	}
for(int i = 0; i < n;i++){
	for(int j = i + 1;j<n;j++){
		for(int k = j + 1;k < n;k++){
			if(arr[i] != arr[j] && arr[j] != arr[k] && arr[i] + arr[j] > arr[k] && arr[i] + arr[k] > arr[j] && arr[k] + arr[j] > arr[i]){
				ctr++;
			}
		}
}
}
printf("%d", ctr);
return 0;
}
