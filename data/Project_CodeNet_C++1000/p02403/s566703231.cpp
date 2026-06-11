#include<stdio.h>

int main(void){
  
  int h[100],w[100],i,j,k,l;
  
  for(i=0;;i++){
    
    scanf("%d %d",&h[i],&w[i]);    

    if(h[i]==0&&w[i]==0)break;
    
  }
  
  for(l=0;l<i;l++){
    
    for(j=0;j<h[l];j++){
      
      for(k=0;k<w[l];k++){
	
	printf("#");
	
      }
    
      printf("\n");  
    
    }

    printf("\n");

  }
  
  return 0;  
   
}