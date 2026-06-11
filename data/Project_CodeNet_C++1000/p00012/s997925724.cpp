#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#include <iomanip>

using namespace std;

bool line(double x1, double y1, double x2, double y2, double xp, double yp){
    return (yp-y1)*(x2-x1) - (y2-y1)*(xp-x1) > 0;
}

int main(){
    vector<double> p(6);
    double xp, yp;
    while(cin >> p[0] >> p[1] >> p[2] >> p[3] >> p[4] >> p[5] >> xp >> yp){
        bool yes = true;
        for(int i = 0; i < 3; i++){
            yes &= !(line(p[0],p[1],p[2],p[3],p[4],p[5]) ^ line(p[0],p[1],p[2],p[3],xp,yp));
            rotate(p.begin(), p.begin()+2, p.end());
        }
        cout << (yes ? "YES" : "NO") << endl;
    }
}