#include<cstdio>
#include<cstring>
#include<iostream>
#include<cstdlib>
#include<cmath>
#include<algorithm>
using namespace std;

double GetLen(double x1,double y1,double x2,double y2){
  return sqrt((y2-y1)*(y2-y1)+(x2-x1)*(x2-x1));
}
double GetAn1(double x1,double y1,double x2,double y2){
  return atan((y2-y1)/(x2-x1));
}
double GetAn2(double a,double b,double c){
  return  acos((b*b+c*c-a*a)/(2*b*c));
}
main(){
  double x1,y1,x2,y2,x3,y3,xp,yp; 
  while(scanf("%lf %lf %lf %lf %lf %lf %lf %lf",&x1,&y1,&x2,&y2,&x3,&y3,&xp,&yp)!=EOF){
    double S,S2;
    double a,b,c,an;
    double cl1,cl2,cl3,anc;

    if( (xp==x1 && yp==y1) || (xp==x2 && yp==y2) || (xp==x3 && yp==y3)){
      printf("YES\n");
      continue;
    }

    a=GetLen(x1,y1,x2,y2);
    b=GetLen(x2,y2,x3,y3);
    c=GetLen(x3,y3,x1,y1);
    an=GetAn2(a,b,c);
    S=0.5*b*c*sin(an);

    cl1=GetLen(x1,y1,xp,yp);
    cl2=GetLen(x2,y2,xp,yp);
    cl3=GetLen(x3,y3,xp,yp);

    anc=GetAn2(a,cl1,cl2);
    S2=0.5*cl1*cl2*sin(anc);

    anc=GetAn2(b,cl2,cl3);
    S2+=0.5*cl2*cl3*sin(anc);

    anc=GetAn2(c,cl3,cl1);
    S2+=0.5*cl3*cl1*sin(anc);
    long long int Si,Si2;
    Si=S*10000000;
    Si2=S2*10000000;
    //  printf("%f %f %f %f %f %f",a,b,c,an*(180/M_PI),S,S2);
    if(Si2<=Si)
      printf("YES\n");
    else printf("NO\n");
  }
}