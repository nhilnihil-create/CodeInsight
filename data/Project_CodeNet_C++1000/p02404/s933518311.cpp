#include<stdio.h>

int main(void){
  
  int h[100],w[100],i,j,k,l;
  
  for(i=0;;i++){
    
    scanf("%d %d",&h[i],&w[i]);    
    
    if(h[i]==0&&w[i]==0)break;
    
  }
  
  for(l=0;l<i;l++){
    
    
    for(j=0;j<w[l];j++){
      
      printf("#");
      
    }
    
    printf("\n");
    
    for(j=2;j<h[l];j++){
      
      printf("#");
      
      for(k=2;k<w[l];k++){
	
	printf(".");
	
      }
      
      printf("#\n");
      
    }   
    
    for(j=0;j<w[l];j++){
      
      printf("#");
      
    }
    
    printf("\n\n");
    
  }
  
  return 0;  
  
}