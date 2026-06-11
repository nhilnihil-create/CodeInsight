#include <stdio.h>

int main(){
	int L;
	int R;
	int d;
	scanf("%d %d %d",&L,&R,&d);
	int c=0;
	for (int i=L;i<=R;i++){
		if(i%d == 0){
			c++;
		}else{
			continue;
		}
	}
	printf("%d",c);
return 0;
}