#include <iostream>
#include <math.h>

using namespace std;
int main(void){
    int a,b,C;
    cin >> a >> b >> C;
    
    double PI = acos(-1);
    double rad;
    rad = C * PI / 180;
    
    
    double h = b*sin(rad);
    double S = (a*h)/2;
    double L = sqrt(pow(a - (b * cos(rad)),2) + h*h) + a + b;
    
    cout << fixed << S << endl;
    cout << fixed << L << endl;
    cout << fixed << h << endl;

}
