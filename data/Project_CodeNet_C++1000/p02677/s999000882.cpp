#include <bits/stdc++.h>
using namespace std;
int main(void){
    long double A,B,H,M;
    cin >> A >> B >> H >> M;
    
    long double C,rad;
    rad=M_PI/180*(30*H+M/2-6*M);
    C=sqrt(A*A+B*B-2*A*B*cos(rad));
    
    cout << fixed << setprecision(10);
    cout << C << endl;
    
}
