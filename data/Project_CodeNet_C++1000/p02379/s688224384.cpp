#include <iostream>
#include <math.h>
#include <iomanip>

using namespace std;

int main(int argc, const char * argv[]) {
    double x1,x2,y1,y2,d;
    cin >> x1 >> y1 >> x2 >> y2;
    d = sqrt(pow(x2-x1,2)+pow(y2-y1,2));
    cout << setprecision(10) <<d << endl;
    return 0;
}