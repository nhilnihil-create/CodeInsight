#include <stdio.h>
int main(){
int a;
scanf("%d",&a);
if(a/100==7){
	printf("Yes");
}
else if(((a/100)-7)%10==0){
	printf("Yes");
}
else if (((a/10)-7)%10==0){
	printf("Yes");
}
else if((a-7)%10==0){
	printf("Yes");
}
else{
	printf("No");
}
return 0;
}
