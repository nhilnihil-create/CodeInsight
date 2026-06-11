#include<iostream>
#include<cmath>
#include<cstdio>
using namespace std;

//x,y structure
typedef struct{
  double x;
  double y;
}XY;

bool flagfirst=true;
bool test=true;

int counter=0;

//function kochCurve
void kochCurve(XY p1,XY p2,int n){
  XY s,u,t;
  //calculate x,y

  s.x=(2*p1.x+p2.x)/3;
  s.y=(2*p1.y+p2.y)/3;
  t.x=(p1.x+2*p2.x)/3;
  t.y=(p1.y+2*p2.y)/3;
  u.x=(t.x-s.x)*cos(M_PI/3)-(t.y-s.y)*sin(M_PI/3)+s.x;
  u.y=(t.x-s.x)*sin(M_PI/3)+(t.y-s.y)*cos(M_PI/3)+s.y;

  //print to 8 decimal places
  if(flagfirst==true) {
    printf("%.8f  %.8f\n",p1.x,p1.y);
    flagfirst=false;
  }
 
  if(n>0){
    kochCurve(p1,s,n-1);
    printf("%.8f  %.8f\n",s.x,s.y);
    kochCurve(s,u,n-1);
    printf("%.8f  %.8f\n",u.x,u.y);   
    kochCurve(u,t,n-1);
    printf("%.8f  %.8f\n",t.x,t.y); 
    kochCurve(t,p2,n-1);

  
  
 
  } 
  

}

int main(){

  int n;
  XY p1,p2;

  //load number
  cin >>n;

  //initialize
  p1.x=0;
  p1.y=0;
  p2.x=100;
  p2.y=0;


  //execute kochCurve
  kochCurve(p1,p2,n);
 
  printf("%.8f  %.8f\n",p2.x,p2.y);   

  return 0;

}