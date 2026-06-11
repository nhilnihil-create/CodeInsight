#include <cstdio>
#include <cmath>
#define SQ(x) ((x)*(x))
using namespace std;
int main(void){
  double x1,x2,y1,y2;
  scanf("%lf%lf%lf%lf",&x1,&y1,&x2,&y2);
  printf("%.8f\n",sqrt(SQ(x1-x2)+SQ(y1-y2)));
  return 0;
}