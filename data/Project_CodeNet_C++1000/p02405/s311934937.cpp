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
  
  for(int i=1; i<=H; i++){
  for(int j=1; j<=W; j++){
    if(i%2==0){
      if(j%2==0){printf("%c",'#');}
      else{printf("%c",'.');}
      }
    else{
      if(j%2==0){printf("%c",'.');}
      else{printf("%c",'#');}
      }
   
    }
    printf("\n");
    }
    
    printf("\n");
   
}
   

}