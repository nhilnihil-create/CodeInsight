#include <stdio.h>
#include <string.h>

int main(){
	int n;
	scanf("%d", &n);
	char c[n+1];
	int flag=1;
	scanf("%s", c);
	if(n%2==1){
		puts("No");
		return 0;
	}else{
		for(int i=0; i<n/2;i++){
			if(c[i] != c[i+n/2]){
				flag=0;
			}
		}
	}
	if(flag){
		puts("Yes");
	}else{
		puts("No");
	}
	return 0;
}