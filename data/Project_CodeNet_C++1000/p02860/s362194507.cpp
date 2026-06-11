#include <stdio.h>
#include <string.h>
int main(){
int n;
scanf("%d",&n);
char arr[n];
scanf("%s",arr);
int z=strlen(arr);
if(z%2){
	printf("No");
	return 0;
}
else{
	for (int i=0;i<z/2;i++){
		if(arr[i]!=arr[i+(z/2)]){
			printf("No");
			return 0;
		}
		else{
			continue;
		}
	}
}
printf("Yes");
return 0;
}