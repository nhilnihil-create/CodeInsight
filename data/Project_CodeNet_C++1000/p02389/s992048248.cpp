#include <iostream>
#include <cstdio>
int cube(int v, int h);


int main(int argc, char *argv[]){
  int v, h,sq,rim;
  scanf("%d",&v);
  scanf("%d",&h);
  sq = cube(v,h);
  auto lmd = [v, h](int v, int h) -> int{return (2*v + 2*h);};
  rim = lmd(v, h);
  std::cout << sq;
  std::cout << " ";
  std::cout << rim << std::endl;
  return 0;
}
int cube(int v, int h){
  int i = v * h;
  return i;
}