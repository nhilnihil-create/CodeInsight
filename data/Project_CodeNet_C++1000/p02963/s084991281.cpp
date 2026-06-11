#include <bits/stdc++.h>
using namespace std;

int main(){
  long long s;
  long long x1, y1, x2, y2;
  cin >> s;
  
  x1=1000000000;
  x2=1;
  if(s==1000000000000000000)y2=1000000000;
  else y2=s/x1+1;
  y1=x1*y2-s;

  printf("0 0 %lld %lld %lld %lld\0",x1,y1,x2,y2);
  return 0;
}
