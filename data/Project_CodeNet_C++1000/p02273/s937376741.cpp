#include <stdio.h>
#include <stdlib.h>
#include <math.h>
 
typedef struct{
  double x;
  double y;
} pos;
 
void kock( int n, pos p1, pos p2) {
 
  pos s, t, u;
 
  if(n == 0) {
    return;
  }
 
  s.x = ( 2 * p1.x + p2.x )/3;
  s.y = ( 2 * p1.y + p2.y )/3;
  t.x = ( p1.x + 2 * p2.x )/3;
  t.y = ( p1.y + 2 * p2.y )/3;
  u.x = (t.x - s.x)*cos(M_PI/3) - (t.y - s.y)*sin(M_PI/3) + s.x;
  u.y = (t.x - s.x)*sin(M_PI/3) + (t.y - s.y)*cos(M_PI/3) + s.y;
 
  kock( n-1, p1, s);
  printf("%f %f\n", s.x, s.y);
  kock( n-1, s, u);
  printf("%f %f\n", u.x, u.y);
  kock( n-1, u, t);
  printf("%f %f\n", t.x, t.y);
  kock( n-1, t, p2);
}
 
int main() {
 
  int n;
  pos start={ 0, 0};
  pos end={ 100, 0};
 
  scanf("%d", &n);
 
  printf("%f %f\n", start.x, start.y);
 
  kock( n, start, end);
 
  printf("%f %f\n", end.x, end.y);
 
  return 0;
 
}