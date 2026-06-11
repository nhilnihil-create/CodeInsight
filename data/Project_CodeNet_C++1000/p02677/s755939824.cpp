#include <bits/stdc++.h>
using namespace std;

int main(){
    long double A, B, H, M;
    cin >> A >> B >> H >> M;
    long double r1,r2;
    long double dist;
    const long double PI=3.14159265358979323846;

    r1=6.0*M;
    r2=30.0*H+0.5*M;
    
    dist=double(A*A+B*B)-double(2*A*B)*cos((r1-r2)*PI/180.0);
    dist=sqrt(dist);
//cout << (long double)cosl(A) << endl;

    cout << setprecision(20) << dist << endl;
}