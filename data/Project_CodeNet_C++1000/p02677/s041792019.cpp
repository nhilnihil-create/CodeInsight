#include<algorithm>
#include<cmath>
#include<iostream>
#include<vector>
#include<string>
using namespace std;
typedef long long ll;

#define REP(i, n) for(ll i=0;i<ll(n); i++)

int main(){

    static const double pi = 3.141592653589763;

    double rh, rm, h, m;
    double angh, angm;
    double anghm;
    double distance;

    cin >> rh >> rm >> h >> m;

    angh  = ((h * 60.0 + m) * 1.0) / 2.0;
    angm  = m * 6.0;
    anghm = abs(angh - angm);
    if(anghm >= 180.0){anghm = 360.0 - anghm;}
    anghm = anghm / 180.0 * pi;


    distance = sqrt(rh*rh*1.0 + rm*rm*1.0 - 2.0*rh*1.0*rm*1.0*cos(anghm));

    printf("%.20f\n", distance);

    return 0;
}
