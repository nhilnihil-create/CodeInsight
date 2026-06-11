#include<iostream>
#include<stdio.h>
using namespace std;

double Circle_menseki(double r);
double Circle_syu(double r);

int main(){
    double r;
    
    cin >> r;
    printf("%f %f",Circle_menseki(r),Circle_syu(r));
    
    return 0;
}

double Circle_menseki(double r){
    return r * r * 3.141592653589;
}
double Circle_syu(double r){
    return 2 * r * 3.141592653589;
}
