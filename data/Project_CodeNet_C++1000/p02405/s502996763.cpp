#include <cstdio>
using namespace std;

void ch(int H, int W){
  for (int i = 0; i < H; ++i) {
    for(int j = 0; j < W; ++j) {
     if((i + j) % 2 == 0){
       printf("#");
     }else{
       printf(".");
     }
    } 
    printf("\n");     
  }
}

int main(){
  int H,W;

  while(1){
    scanf("%d%d", &H,&W); 
    if(H == 0 && W == 0) return 0;
    
    ch(H, W);
    printf("\n");
  }
}