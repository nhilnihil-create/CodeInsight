#include <iostream>
#include <iomanip>
#include <math.h>

using namespace std;

double x_1, x_2, y_1, y_2;
double distances;

double distance(double x_1, double y_1, double x_2, double y_2);

int main(void){
    
    cin >> x_1 >> y_1 >> x_2 >> y_2;
    distances = distance(x_1, y_1, x_2, y_2);
    cout << fixed << setprecision(8) << distances;
    
    return 0;
    
}

double distance(double x_1, double y_1, double x_2, double y_2){
    return sqrt((x_2 - x_1) * (x_2 - x_1) + (y_2 - y_1) * (y_2 - y_1));
}