#include <stdio.h>
int main(){
	int n;
	scanf("%d", &n);
	
	int a[n], b[n];
	
	for(int i = (n-1); i >= 0; i--){
		scanf("%d", &a[i]);
	}
	for(int i = 0; i < n; i++){
		if( i == (n-1))
			printf("%d\n", a[i]);
		else
		printf("%d ", a[i]);
	}
	
  return 0;
}