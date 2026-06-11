#include <stdio.h>
int main()
{
  int m,f,r,summf;
  while(1){
    scanf("%d %d %d",&m,&f,&r);
    if(m==-1&&f==-1&&r==-1){
      break;
    }
    summf=m+f;
    if(m==-1||f==-1){
      printf("F\n");
    }else
      if(80<=summf){
	printf("A\n");
      }else
	if(65<=summf&&summf<80){
	  printf("B\n");
	}else
	  if(50<=summf&&summf<65){
	    printf("C\n");
	  }else
	    if(30<=summf&&summf<50){
	      if(r>=50){
		printf("C\n");
	      }else printf("D\n");
	    }else
	      if(summf<30){
		printf("F\n");
	      }
  }
  return 0;
}