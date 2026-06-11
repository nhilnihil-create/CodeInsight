#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <string>
#include <vector>
#include <algorithm>
#define rep(i,e)for(int i=0;i<e;i++)
using namespace std;

int main(){
    int n, i, j;
    double x1, y1 , x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    double D = pow(x1-x2,2)+pow(y1-y2,2);
    printf("%.8f\n", sqrt(D));
    return 0;
}
