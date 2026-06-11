#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    long long s;
    cin >> s;
    if(s == 1e18){
        long long a = 1e9;
        printf("0 0 %lld 1 0 %lld\n", a, a);
        return 0;
    }
    long long x0 = 0, y0 = 0, x1, y1 = 0, x2 = 0, y2;
    x1 = 1e9;
    y1 = 1;
    x2 = 1e9 - (s % (long long)1e9);
    y2 = (s+x2) / 1e9;

    cout << x0 << " " << y0 << " " << x1 << " " << y1 << " " << x2 << " " << y2 << endl;
    return 0;
}