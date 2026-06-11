#include <iostream>
#include <stdio.h>
#include <string>
#include <math.h>
int main()
{
    int a,b,c;
    double s,h,tes,rad,tei,teia;
    std::cin >> a >> b >> c;
    //syuu no nagasa wo dasu
    rad=c*M_PI/180;
    tes=a*a+b*b-2*a*b*cos(rad);
    tes=sqrt(tes);
    s=a+b+tes;
    //menseki wo dasu
    tei=s/2;
    teia=tei*(tei-a)*(tei-b)*(tei-tes);
    teia=sqrt(teia);
    //takasa wo dasu
    h=teia*2/a;
    //syousuu de hyouji
    printf("%.8f ", teia);
    printf("%.8f ", s);
    printf("%.8f \n", h);
    return 0;
}