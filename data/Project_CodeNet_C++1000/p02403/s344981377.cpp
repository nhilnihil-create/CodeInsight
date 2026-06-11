#include <stdio.h>

int main(void)
{
	int h,w;
	int i,j;

	do{
		scanf("%d%d",&h,&w);
		if(h == 0	&&	w == 0)
		     break;
		
		for(i = 0;	h > i;	i++){
		      for(j = 0;	w > j;	j++)
		      	    printf("#");
		      puts("");
		}
		puts("");
	}while(1);
	
	return(0);
}