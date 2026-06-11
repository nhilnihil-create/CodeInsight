#include <stdio.h>
int main(){
	int h,a,i,total;
	scanf ("%d",&h);
	scanf ("%d",&a);
	if (h%a==0){
		i=h/a;
		printf ("%d",i);
	}
	else{
		total = (h/a)+1;
		printf ("%d",total);
	}
	return 0;
}