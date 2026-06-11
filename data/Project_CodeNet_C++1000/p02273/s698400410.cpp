#include <iostream>
#include <cmath>
#include <cstdio>
 
const static double PI = 4*atan(1.0);
 
using namespace std;
 
 
int count=0;
 
 
  
void Koch_curve(int n, double p1x, double p1y, double p2x, double p2y){
    double sx, sy, tx, ty, ux, uy;
     
    if(n == 0){
        //cout << p2x << ' ' << p2y << endl;
        printf("%.4lf %.4lf\n", p2x, p2y);
        count++;
    }
    else{
        n--;
        sx = p1x + (p2x-p1x)*(1.0/3.0);
        sy = p1y + (p2y-p1y)*(1.0/3.0);
        tx = p1x + (p2x-p1x)*(2.0/3.0);
        ty = p1y + (p2y-p1y)*(2.0/3.0);
 
        //求め方は http://www.infra.kochi-tech.ac.jp/takagi/Survey2/3PolarRect.pdf　
        // 極座標の回転　（二次元回転行列）
        ux= sx + (tx-sx)*cos(PI/3.0) - (ty-sy)*sin(PI/3.0);
        uy= sy + (tx-sx)*sin(PI/3.0) + (ty-sy)*cos(PI/3.0);
 
        Koch_curve(n, p1x, p1y, sx, sy);
        Koch_curve(n, sx, sy, ux, uy);
        Koch_curve(n, ux, uy,tx, ty);
        Koch_curve(n, tx, ty, p2x, p2y);
    }
     
}
  
int main() {
    int n;
     
    cin >> n;
    //cout.setf(ios::fixed, ios::floatfield); //固定小数表記 
    //cout << 0.0 << ' ' << 0.0 << endl;
    printf("%.4lf %.4lf\n", 0.0, 0.0);
    Koch_curve(n, 0.0, 0.0, 100.0, 0.0);
         
        return 0;
}
