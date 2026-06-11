#include<bits/stdc++.h>
#include<iomanip>
using namespace std;

int main(){
    int A, B, H, M;
    cin >> A >> B >> H >> M;
    double Aangle = 360 / 12 * H + 360 * M / 12 / double(60), Bangle = 360 * M / 60;
    double theta = Bangle - Aangle;
    if(theta < 0) theta = -theta;
    if(theta > 180) theta = 360 - theta;
    double rad = theta  * M_PI / 180;
    double c = sqrt(A * A + B * B - 2 * A * B * cos(rad));
    cout << fixed;
    cout << setprecision(20) << c << endl;
}