                             //SILENT KILLER
#include<bits/stdc++.h>
//typedef long long ll;
using namespace std;
#define PI 3.14159265358979323846
int main()
{
    long double A,B,H,M;
    cin >> A >> B >> H >> M;
   long double theta = 2*PI*((H+M/60)/12 - M/60);
    long double c = sqrtl(A*A + B*B - 2*A*B*cos(theta));
    cout  << setprecision(20) << c << endl;
}
