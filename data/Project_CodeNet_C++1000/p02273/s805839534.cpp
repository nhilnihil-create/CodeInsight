#include<iostream>
#include<iomanip>
#include<math.h>
using namespace std;
int n;

void KochCurve(double start_x, double end_x, double start_y,double end_y,int n){
    if (n>0){
        double x_1=(2*start_x+end_x)/3, y_1=(2*start_y+end_y)/3;
        double x_3=(start_x+2*end_x)/3, y_3=(start_y+2*end_y)/3;
        double x_2=start_x+(end_x-start_x)/2 + sqrt(3)*(start_y-end_y)/6;
        double y_2=start_y+(end_y-start_y)/2 + sqrt(3)*(end_x-start_x)/6; 
        KochCurve(start_x, x_1, start_y, y_1, n-1);
        cout <<setprecision(10)<< x_1 << " " << y_1 << "\n";
        KochCurve(x_1, x_2, y_1, y_2, n-1);
        cout << x_2 << " " << y_2 << "\n";
        KochCurve(x_2, x_3, y_2, y_3, n-1);
        cout << x_3 << " " << y_3 << "\n";
        KochCurve(x_3, end_x, y_3, end_y, n-1);    
    }
}

int main(){
    cin >> n;
    cout << 0.0 << " " <<  0.0 << "\n";  
    KochCurve(0.0,100.0, 0.0,0.0,n);
    cout << 100.0 << " " << 0.0 << "\n"; 
}
