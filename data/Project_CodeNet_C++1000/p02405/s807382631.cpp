#include<stdio.h>

int main(void){
  
  int h[100],w[100],i,j,k,l;
  
  for(i=0;;i++){
    
    scanf("%d %d",&h[i],&w[i]);    
    
    if(h[i]==0&&w[i]==0)break;
    
  }
  
  for(j=0;j<i;j++){
    
    for(k=1;k<=h[j];k++){
      
      for(l=1;l<=w[j];l++){
	
	if((k+l)%2==0)printf("#");
	else printf(".");
	
      }
      
      printf("\n");
	
	}
  
    printf("\n");
      
      }
  
  return 0;  
  
}