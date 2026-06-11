#include <iostream>
using namespace std;
#include <math.h>
#include <cstdio>


int main()
{
  double dis = 0.0 , x1 , x2 , y1 , y2 , f = 0.0;
  
  cin >> x1 >> y1 >> x2 >> y2;
  
  if( x1 >= x2 && y1 >= y2 ) f = ( x1 - x2 ) * ( x1 - x2 ) + ( y1 - y2 ) * ( y1 - y2 );
  else if( x1 <= x2 && y1 <= y2 ) f = ( x2 - x1 ) * ( x2 - x1 ) + ( y2 - y1 ) * ( y2 - y1 );
  else if( x1 >= x2 && y1 <= y2 ) f = ( x1 - x2 ) * ( x1 - x2 ) + ( y2 - y1 ) * ( y2 - y1 );
  else if( x1 <= x2 && y1 >= y2 ) f = ( x2 - x1 ) * ( x2 - x1 ) + ( y1 - y2 ) * ( y1 - y2 );
  
  // f = x1 * x2 * y1 * y2;
  dis = sqrt(f); 
  
  printf("%.8f\n",dis);
  
  return 0;
}