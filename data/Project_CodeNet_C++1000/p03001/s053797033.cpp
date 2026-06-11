#include <iostream>
#include <vector>
#include <set>
#include <map>
using namespace std;

int main() {
    int w, h, x, y;
    cin >> w >> h >> x >> y;
    double ans = (double)w*h/2;
    int num = (w==x*2 && h==y*2) ? 1 : 0;
    printf("%.10f %d\n", ans, num);
    return 0;
}