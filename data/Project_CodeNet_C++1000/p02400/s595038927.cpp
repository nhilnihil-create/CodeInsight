#include<iostream>
#include<math.h>
using namespace std;
int main(){
    double r, S, L;
    cin >> r;
    S = r*r*M_PI;
    L = 2*r*M_PI;
    
    cout <<fixed<< S << " " <<fixed<< L <<endl;
    return 0;
}
