#include <bits/stdc++.h>
                    
using namespace std;
struct Point{       
  double x,y;       
};                  
void Koch(int,Point,Point);
                    
int main(){         
 int num;           
 Point p1,p2;       
 cin >> num;        
 /*?????????*/         
 p1.x  = 0;         
 p1.y = 0;          
 p2.x = 100;        
 p2.y = 0;          
 printf("%.8f %.8f\n",p1.x,p1.y);
 Koch(num,p1,p2);   
 printf("%.8f %.8f\n",p2.x,p2.y);
 return 0;          
}                   
                    
                    
void Koch(int num, Point p1, Point p2){
  Point p3,p4,p5;   
  double rad;       
  if( num == 0){    
    return;         
  }                 
  rad = M_PI*60.0 / 180.0;/*??????*/
  p3.x = (2.0 * p1.x + 1.0* p2.x) / 3.0;
  p3.y = (2.0 * p1.y + 1.0 * p2.y) / 3.0;
  p4.x = (1.0 * p1.x + 2.0* p2.x) / 3.0;
  p4.y = (1.0 * p1.y + 2.0 * p2.y) / 3.0;
  p5.x = (p4.x - p3.x)*cos(rad) - (p4.y - p3.y)*sin(rad) + p3.x;
  p5.y = (p4.x - p3.x)*sin(rad) + (p4.y - p3.y)*cos(rad) + p3.y;
                    
  Koch(num-1, p1, p3);
  printf("%.8f %.8f\n",p3.x,p3.y);
  Koch(num-1, p3, p5);
  printf("%.8f %.8f\n",p5.x,p5.y);
  Koch(num-1, p5, p4);
  printf("%.8f %.8f\n",p4.x,p4.y);
  Koch(num-1,p4,p2);                                                                                                                                                                          
}