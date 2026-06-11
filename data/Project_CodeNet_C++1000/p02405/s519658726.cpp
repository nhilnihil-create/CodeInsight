#include <stdio.h>

int main(void)
{
  int h,w;
  int i,j;
  int co = 0;
  int ch = 0;


  do{
    scanf("%d%d",&h,&w);
    if(h == 0	&&	w == 0)
      break;

    for(i = 0; h > i; i++){
      for(j = 0; w > j;	j++){
	if((ch%2)==0 && (co%2)==0)
	  printf("#");
	else if((ch%2)==0 && (co%2)==1)
	  printf(".");
	else if((ch%2)==1 && (co%2)==0)
	  printf(".");
	else
	  printf("#");
	ch++;
      }
      co++;
      ch=0;
      puts("");
    }
    puts("");
    co=0;
  }while(1);

  return(0);
}