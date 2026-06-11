#include<iostream>
int main()
{
  int x,y;
  int ans[4]={0,300000,200000,100000};
  std::cin>>x>>y;
  if(x==1&&y==1)
    std::cout<<1000000<<std::endl;
  else {
    int tot=0;
    if(x<4) tot+=ans[x];
    if(y<4) tot+=ans[y];
    std::cout<<tot<<std::endl;
  }
  return 0;
}