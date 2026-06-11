#include <stdio.h>
#include <string.h>
#define ll long long int

int main(){
	int n, cek = 0;
	scanf("%d", &n);
	int num[n];
	for(int i = 0; i<n; i++){
		scanf("%d", &num[i]);
	}
	for(int i = 0; i<n; i++){
		for(int j = i + 1; j<n; j++){
			for(int k = j+1; k<n; k++){
				if((num[i] != num[j]) && (num[j] != num[k]) && (num[k] != num[i])){
					if((num[i] + num[j] > num[k]) && (num[j] + num[k] > num[i]) && (num[k] + num[i] > num[j])){
						cek++;
				}
			}
		}
	}
}
	printf("%d\n",	cek);
	
	return 0;
}