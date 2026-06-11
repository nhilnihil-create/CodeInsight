#include<iostream>
using namespace std;
#include<cmath>

int main() {
        double x1, y1, x2, y2;
        double result, temp;
        cin >> x1 >> y1 >> x2 >> y2;
        temp = pow(x1 - x2, 2) + pow(y1 - y2, 2);
        result = sqrt(temp);
        cout << fixed;
        cout << result << endl;
        return 0;
}