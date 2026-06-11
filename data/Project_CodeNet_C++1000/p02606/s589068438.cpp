#include <stdio.h>
int main(){
	int L,R,d;
	int a=0;
	scanf("%d %d %d",&L,&R,&d);
	
	for (L;L<=R;L++){
		if(L%d==0){
			a++;
		}
	}
	printf("%d",a);
	
	
	
	return 0;	
	}
