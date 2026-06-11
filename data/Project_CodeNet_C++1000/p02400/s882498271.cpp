#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;

using std::acos;

int main(){
        double const pi1 = acos(-1.0);
        double r;
        double S; // menseki                                                   
        double l; // enshuu                                                    
        cin >> r;

        S = pi1*pow(r,2.0);
        l = 2.0*pi1*r;

        printf("%lf %lf\n", S, l);
        return 0;
}