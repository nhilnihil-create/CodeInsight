#include <iostream>
#include <math.h>
#include <cstdio>
#include <utility>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

int main() {

while(1){
  
  int H,W;
  
  scanf("%d %d",&H,&W);
  
  if(H==0){break;}
  
  for(int i=0; i<H; i++){
  for(int j=0; j<W; j++){
    if(i==0||i==H-1){
       printf("%c",'#');
    }  
    else{
      if(j==0||j==W-1){
        printf("%c",'#');
        }
      else{
        printf("%c",'.');
        }
    }
   
    }
    printf("\n");
    }
    
    printf("\n");
   
}
   

}