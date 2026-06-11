#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;

int yf(int x)
{
  return x*x;
}


int main()
{
  int d;
  int ans;
  while( scanf("%d",&d) != EOF ){
    for(int i=0; i<(600/d); i++){
      ans = ans + d * yf((600 - (i+1)*d));
      //printf("%d\n",ans);
    }
    printf("%d\n",ans);
    ans = 0;
  }
}