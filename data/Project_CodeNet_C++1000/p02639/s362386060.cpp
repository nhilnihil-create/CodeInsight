#include<cstdio>
int main() {
  for(int i=1;i<=5;++i){
    int x;
    std::scanf("%d",&x);
    if(!x)std::printf("%d\n",i);
  }
}