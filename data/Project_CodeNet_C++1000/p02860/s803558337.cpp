#include <stdio.h>

int main() {
	
	int n;
	scanf("%d", &n);
	
	char s[n];
	scanf("%s", s);
	
	if (n%2==1){
		printf("No\n");
		return 0;
	}
	
	for(int i=0, j=n/2; j<n; i++, j++){
		if(s[i]!=s[j]){
			printf("No\n");
			return 0;
		}
	}

	printf("Yes\n");


    return 0;
}