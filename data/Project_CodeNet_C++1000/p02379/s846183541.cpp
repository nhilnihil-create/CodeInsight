#include<iostream>
#include<iomanip>
#include<cmath>

using namespace std;

double Length(double x1, double y1, double x2, double y2) {

    double X;

    X = sqrt(pow((x2-x1), 2) + pow((y2-y1), 2));

    return X;
}

int main () {

    double x1, y1;
    double x2, y2;

    cin >> x1 >> y1 >> x2 >> y2;

    double answer = Length(x1, y1, x2, y2);

    cout << fixed;
    cout << setprecision(5) << answer << endl; 

    return 0;

}
