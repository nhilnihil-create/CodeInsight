#include <stdio.h>
int main(){
  int H,W,h,w;
  while(1){
scanf("%d %d",&H,&W);
 for(h=1;h<=H;h++){
      if(h==1){ 
	for(w=1;w<=W;w++){
	  if(w<W){
	printf("#");
      }
      else if(w==W){
	printf("#\n");
      }
	}}
      else if(h>0&&h<H){
	for(w=1;w<=W;w++){
	  if(w==1){
	  printf("#");
	}
	else if(w>0&&w<W){
	  printf(".");
	}
	else if(w==W){
	  printf("#\n");
	}
      }}
      else if(h==H){
	for(w=1;w<=W;w++){
if(w<W){
	  printf("#");
	}
	else if(w==W){
	  printf("#\n");
	}
      }
      }}
    if(H!=0){
      if(h=H+1){
   printf("\n");
 }
    }
    if(H==0&&W==0){
    break;
    }
 }

  return 0;
}