#include <stdio.h>
#include <string.h>
int  main() {
	int leng, x = 0, y = 0;
	int counter = 0;
	int a1 = 0;
	int a2 = 0;
	char str[105];
	char str2[105];
	char str3[105];
	scanf("%d", &leng);
	scanf("%s", str);
	for(int j = leng/2; j < leng;j++){
		str2[x] = str[j];
		a1 += str2[x];
		x++;
		
	}
	for(int i = 0;i < leng/2;i++){
		str3[y] = str[i];
		a2 += str3[y];
		y++;
	}
if(a1 == a2 && (a1 != 0 && a2!= 0)){
	printf("Yes");
}else{
	printf("No");
}


   return 0;
}