#include <iostream>
using namespace std;
long long x,i,j;
int main() {
 scanf("%lld",&x);
 for(i=-5000;i<=5000;i++)
  for(j=-5000;j<=5000;j++)
   if(i*i*i*i*i-j*j*j*j*j==x) {
    printf("%lld %lld\n",i,j);
    return 0;
   }
}