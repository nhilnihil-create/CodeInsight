#include<bits/stdc++.h>
using namespace std;

struct point{
  double x, y;
};

void koch(int n, point p1, point p2){
  point  p3, p4, p5;
  double rad60=M_PI*60.0/180.0;
  
  if(n==0) return;
  
  p3.x=(2.0*p1.x+p2.x)/3.0;
  p3.y=(2.0*p1.y+p2.y)/3.0;

  p4.x=(p1.x+2.0*p2.x)/3.0;
  p4.y=(p1.y+2.0*p2.y)/3.0;

  p5.x=(p4.x-p3.x)*cos(rad60)-(p4.y-p3.y)*sin(rad60)+p3.x;
  p5.y=(p4.x-p3.x)*sin(rad60)+(p4.y-p3.y)*cos(rad60)+p3.y;

  koch(n-1, p1, p3);
  printf("%.8f %.8f\n", p3.x, p3.y);
  koch(n-1, p3, p5);
  printf("%.8f %.8f\n", p5.x, p5.y);
  koch(n-1, p5, p4);
  printf("%.8f %.8f\n", p4.x, p4.y);
  koch(n-1, p4, p2);
}

int main(void){
  int n;
  point p1, p2;
  
  scanf("%d", &n);

  p1.x=0.0; p1.y=0.0;
  p2.x=100.0; p2.y=0;
  
  printf("%.8f %.8f\n", p1.x, p1.y);
  koch(n, p1, p2);
  printf("%.8f %.8f\n", p2.x, p2.y);
  
  return 0;
}

