#include<iostream>
#include<cstdio>
#include<math.h>
using namespace std;

int main() {
    double x1, x2, y1, y2;
    double ans;
    cin >> x1 >> x2 >> y1 >> y2;
    ans = sqrt(((x1 - y1)*(x1 - y1) + (x2 - y2)*(x2 - y2)));
    printf("%8lf\n", ans);
    
    return 0;
}
