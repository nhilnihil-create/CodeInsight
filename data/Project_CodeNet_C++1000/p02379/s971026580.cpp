#include <iostream>
#include <cstring>
#include <vector>
#include <cctype>
#include <cstdio>
#include <cmath>
using namespace std;
#define rep(i, n) for( int i = 0; i < n; i++ )
typedef vector<int> vec;

int main(){
    double x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    double dist = (sqrt)((x2-x1)*(x2-x1)+(y2-y1)*(y2-y1));
    // cout << dist << endl;
    printf("%.6f\n", dist);
}