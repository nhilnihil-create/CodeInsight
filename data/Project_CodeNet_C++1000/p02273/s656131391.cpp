#include<stdio.h>
#include<math.h>
   
typedef struct{
  double x;
  double y;
}koch;
 
void fractal(int,koch,koch);
  
int main(){
   
  koch p1,p2;
  int n;
   
  p1.x = 0;
  p2.x = 100;
  p1.y = 0;
  p2.y = 0;
   
  scanf("%d",&n);
   
  printf("%f %f\n",p1.x,p1.y);
  fractal(n,p1,p2);
  printf("%f %f\n",p2.x,p2.y);
   
  return 0;
}
 
void fractal(int n, koch p1, koch p2){
  
  if(n==0) return;
  koch s,t,u;
   
  s.x = (p2.x-p1.x)/3+p1.x;
  s.y = (p2.y-p1.y)/3+p1.y;
  t.x = 2*(p2.x-p1.x)/3+p1.x;
  t.y = 2*(p2.y-p1.y)/3+p1.y;
  u.x = (t.x-s.x)/2-sqrt(3)/2*(t.y-s.y)+s.x;
  u.y = (t.y-s.y)/2+sqrt(3)/2*(t.x-s.x)+s.y;
   
  fractal(n-1,p1,s);
  printf("%f %f\n",s.x,s.y);
     
  fractal(n-1,s,u);
  printf("%f %f\n",u.x,u.y);
     
  fractal(n-1,u,t);
  printf("%f %f\n",t.x,t.y);
   
  fractal(n-1,t,p2);
}