#include<cstdio>

int main() {
  //入力
  int a,b,c;
  std::scanf("%d%d%d",&a,&b,&c);
  
  if(a < b && b < c) {
    std::printf("Yes\n");
  }
  else {
    std::printf("No\n");
  }
  return 0;
}
