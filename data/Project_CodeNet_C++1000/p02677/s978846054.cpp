#include<iostream>
#include <string>
#include <cstring>
#include <cmath>
#include <stdio.h>
using namespace std;
 
int main(){
    static const double pi = 3.14159265358979323846;
    int A, B, H, M;
    cin>> A>>B>>H>>M;
    double angle1 = 2*pi*H/12.0 + 2*pi/12.0*M/60.0;
    double angle2 = 2*pi*M/60.0;

    double x1 = A*cos(angle1);
    double y1 = A*sin(angle1);
    double x2 = B*cos(angle2);
    double y2 = B*sin(angle2);

    double  dist = sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
    //cout << dist<<endl;
    printf("%.20lf",dist);
    return 0;
}