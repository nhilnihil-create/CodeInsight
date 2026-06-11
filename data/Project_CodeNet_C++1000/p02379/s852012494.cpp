#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;
int main(){
    double x1, y1, x2, y2, dist;
    cin >> x1 >> y1 >> x2 >> y2;
    if(x1 == x2){
        dist = abs(y1 - y2);
    } else if(y1 == y2){
        dist = abs(x1 - x2);
    } else {
        dist = sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));
    }
    printf("%lf\n", dist);
    return 0;
}
