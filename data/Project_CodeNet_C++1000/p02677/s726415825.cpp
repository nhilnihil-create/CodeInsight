#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

double calc_len(double a, double b, double ceta) {
    double tmp = a*a+b*b-2*a*b*cos(ceta);
    return sqrt(tmp);
}

double deg2rad(double ceta) {
    return ceta*M_PI/180;
}

double hm2deg(double H, double M) {
    double tmp = abs(360*(H*60+M)/(60*12) - 360*M/60);
    if(tmp>180) {
        tmp = 360-tmp;
    }
    return tmp;
}

int main() {
    double A, B, H, M;
    cin >> A >> B >> H >> M;
    
    cout << setprecision(20) << calc_len(A, B, deg2rad(hm2deg(H, M))) << endl;

    return 0;
    
}