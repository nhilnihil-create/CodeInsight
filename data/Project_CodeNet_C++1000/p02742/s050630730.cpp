#include<iostream>
#include<cmath>

using namespace std;

int main(){
  unsigned long long H, W;
  cin >> H >> W;
  if(H==1){
    printf("1\n");
  }else if(W==1){
    printf("1\n");
  }else{
    printf("%llu\n", ((H * W) + 1) / 2);
  }
}
