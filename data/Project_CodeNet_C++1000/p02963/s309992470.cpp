#include<bits/stdc++.h>
using namespace std;
int main()
{
 long long int n;
 scanf("%lld",&n);
 long long int x1,y1,x2,y2;
 bool p=1 ;
 long long int j=0;
 long long int i =sqrt(n); 
  x1 = sqrt(n)+0.9;
  y1=1;
  y2=sqrt(n)+0.9;
  x2=x1*y2-n;
  printf("0 0 %lld %lld %lld %lld",x1,y1,x2,y2);
  return 0;
}