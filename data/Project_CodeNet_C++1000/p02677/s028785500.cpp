#include <bits/stdc++.h>
#include <iostream>
#include <algorithm>
#include <string>
#include <math.h>
using namespace std;



int A,B,H,M;
double theta;

int main(){

    cin >>A >> B >> H >>M;

    long double timeh = H + (double)M/60;
    long double thetaA = timeh * 2 * M_PI / 12; // 0< < pi
    long double thetaB = timeh * 2 * M_PI; // 0 < < 2 pi
    long double theta = thetaB - thetaA;
   if(theta> M_PI)
    {
        theta = 2* M_PI - theta;
    }

    long double l = sqrt(A*A + B*B - 2 * A * B * cos(theta));
    cout <<  fixed << setprecision(11) <<l << endl;

    return 0;

}
