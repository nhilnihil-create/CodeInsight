#include<iostream>
#include<cmath>
#include<iomanip>

using namespace std;

int main(){
        double x1,y1,x2,y2;
        cin >> x1 >> y1 >> x2 >> y2; 
        cout << setprecision(20);
        cout << pow( (x1-x2)*(x1-x2) + (y1-y2)*(y1-y2) ,0.5) << endl;

return 0;
}