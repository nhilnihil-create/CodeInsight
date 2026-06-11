#include <iostream>
using namespace std;
#define ll long long  
int main()
{    
  ll a,b;
  scanf("%lld",&a);
  b=360;
  while(b%a != 0)
    b+=360;
  printf("%lld",b/a);
  
  return 0;
}
