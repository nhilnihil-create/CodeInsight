#include <cstdio>

using namespace std;

int main(){
  int a,b,d,r;
  double f;

  scanf("%d%d", &a,&b); 
  d=a/b;  r=a%b;
  f=1.00*a/b;
  printf("%d %d %.6lf\n",d,r,f);
 
  return 0;
}