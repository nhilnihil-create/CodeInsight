#include <iostream>
#include <stdio.h>
#include <string.h>
#include <math.h>

using namespace std;

int main(){
    double a, b, c;
    double s1, l1, h1;
    double temp1;
    
    s1=0;
    l1=0;
    h1=0;
    
    cin >> a >> b >> c;
    
    //cout << M_PI << endl;
    temp1=sin(M_PI/180 * c);
    
    //cout << temp1 << endl;
    
    s1 = 0.5 * a * b * temp1;
    l1 = a + b + sqrt(a*a+b*b-2*a*b*cos(M_PI/180 * c));
    //cout << s1 << endl;
    h1 = b * temp1;
    
    printf("%-20.8f\n",s1);
    printf("%-20.8f\n",l1);
    printf("%-20.8f\n",h1);
    
    return 0;
}