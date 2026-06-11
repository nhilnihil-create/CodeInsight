#include <iostream>
#include <cmath>
using namespace std;

void koch(long double x0,long double y0,long double x1,long double y1,int d){
    if(d == 0){
        cout << x0 << ' ' << y0 << endl;
        if(x1 == 100.0 && y1 == 0){
            cout << x1 << ' ' << y1 << endl;
        }
    }
    else{
        long double xa = (x0*2.0+x1*1.0)/3.0;
        long double ya = (y0*2.0+y1*1.0)/3.0;
        long double vecx = (x1-x0)/3.0;
        long double vecy = (y1-y0)/3.0;
        long double midx = (x0+x1)*0.50;
        long double midy = (y0+y1)*0.50;
        long double xb = midx + vecy * (-sqrt(3.0)*0.50);
        long double yb = midy + vecx * ( sqrt(3.0)*0.50);
        long double xc = (x0*1.0+x1*2.0)/3.0;
        long double yc = (y0*1.0+y1*2.0)/3.0;
        
        koch(x0,y0,xa,ya,d-1);
        koch(xa,ya,xb,yb,d-1);
        koch(xb,yb,xc,yc,d-1);
        koch(xc,yc,x1,y1,d-1);
    }
}

int main(void){
    int n;
    cin >> n;
    koch(0.0,0.0,100.0,0.0,n);
    return 0;
}