#include <stdio.h>
int main(){
  int H,W,h,w;
  while(1){
    scanf("%d %d",&H,&W);  
    for(h=1;h<=H;h++){  
    if(h%2==1){
      for(w=1;w<=W;w++){
	if(w<W){	
	  if(w%2==1){
	  printf("#");
	}
	else if(w%2==0){
	  printf(".");
	}}
	else if(w==W){
	  if(w%2==0){
	    printf(".\n");
	  }
	  else if(w%2==1){
	    printf("#\n");
	  }}
      }}
     if(h%2==0){
      for(w=1;w<=W;w++){
	if(w<W){	
	  if(w%2==1){
	  printf(".");
	}
	else if(w%2==0){
	  printf("#");
	    }
	}
	else if(w==W){
	  if(w%2==0){
	    printf("#\n");
	  }
	  else if(w%2==1){
	    printf(".\n");
	  }
	}
      }
     }
    }
    if(H!=0){
      if(h==H+1){
	printf("\n");
      }
    }
    
	if(H==0&&W==0){
      break;
	}
      }
  return 0;
}