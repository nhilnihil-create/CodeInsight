#include <stdio.h>
#include <string.h>
 
int main (){
	int n;
	char str[100005];

	scanf("%d", &n);
	scanf("%s", str);
	
	int len = strlen(str);
	
	for (int i=0; i<len; i++){
		if (str[i] + n > 'Z'){
			str[i] -= 26- n;
		}
		else{
			str[i] += n;
		}
	}
	
	printf("%s", str);
	return 0;
}