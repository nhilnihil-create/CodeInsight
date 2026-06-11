#include<bits/stdc++.h>
using namespace std;

int main(){
    int a, b;
    double h, m;

    cin>> a >> b >> h >> m;
    double theata;
    theata = min(abs(30*h+0.5*m - 6*m), 360 - abs(30*h+0.5*m - 6*m));
    //cout<< fixed<<setprecision(9) << theata <<endl;
    theata /= 180;
    //cout<< fixed<<setprecision(9) << theata <<endl;
    //cout<< fixed<<setprecision(9) << cos(M_PI*theata) <<endl;    

    cout<< fixed<<setprecision(9) << sqrt(a*a + b*b - 2*a*b*cos(M_PI*theata)) <<endl;  

    return 0;
}