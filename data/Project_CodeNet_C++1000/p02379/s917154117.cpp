#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <string>

#include<stdio.h>
#include<math.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

using namespace std;

int main(){

  double x1,x2,y1,y2;
  double ans;

  scanf("%lf %lf %lf %lf",&x1,&y1,&x2,&y2);

  ans=sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));

  printf("%.8f\n",ans);

  return 0;
}