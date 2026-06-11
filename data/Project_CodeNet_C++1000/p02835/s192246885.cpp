#include <stdio.h>

int main()
{
  int A1;
  int A2; 
  int A3;
  int Total;
  scanf("%d", &A1);
  scanf("%d", &A2);
  scanf("%d", &A3);
  Total = A1 + A2 + A3;
  if(Total>=22){
  	printf("bust\n");
  }
  else{
  	printf("win\n");
  }
	 
  return 0;
}