#include <bits/stdc++.h>
using namespace std;

int main(){
    int A, B, H, M;
    cin >> A >> B >> H >> M;

    long double thetah, thetam, theta;
    thetah = 0.5 * (H * 60 + M);
    thetam = M * 6;
    theta = abs(thetam - thetah);

    long double l;
    l = sqrt((A * A + B * B) - (2 * (A * B) * cos((theta / 360) * 2 * M_PI)));

    printf("%20.20Lf", l);
    return 0;
}