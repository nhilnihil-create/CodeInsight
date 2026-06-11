#include <iostream>
#include <array>

int main() {
  int a,b;
  while(std::cin >> a >> b){
    if(a!=0&&b!=0){
      int c;
      std::cin >> c;
      int town[a+1][b+1]={};
      int x,y;
      for(int n=0;n<c;++n){
        std::cin >> x >> y;
        town[x][y]=-1;
      }
      town[1][1]=1;
      for(int sum=3;sum<=a+b;++sum){
        for(int t=std::min(sum-1,a);t>0 &&sum-t<=b;--t){
          //if(sum-t<=b){
          	//std::cout << t;
            if(town[t][sum-t]==-1){
              town[t][sum-t]=0;
            }else{
              town[t][sum-t] = town[t-1][sum-t]+town[t][sum-t-1];
            }
          //}
        }
      }
      std::cout << town[a][b] << std::endl;
    }else{
      break;
    }
  }
  return 0;
}