#include<iostream>
#include<string>
#include<cmath>
#include<cstdio>
using namespace std;
int main(){
    double x1,x2,y1,y2,takasa,yoko,kyori,takasa2,yoko2,goukei;
    cin>>x1>>y1>>x2>>y2;
    takasa=y2-y1;
    yoko=x2-x1;
    takasa2=takasa*takasa;
    yoko2=yoko*yoko;
    goukei=takasa2+yoko2;
    kyori=sqrt(goukei);
    printf("%f",kyori);
    cout<<endl;
    return 0;
}