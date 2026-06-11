#include<iostream>
#include<string>
#include<stdio.h>
#include <algorithm>
#include <set>
#include<math.h>
#include<vector>
#include<iomanip>
#include <cstdio>

using namespace std;

int main(){
    double w,h,x,y;cin >> w >> h >> x >> y;
    double m=0.0;
    int cnt = 0;
    m = (w*h) /2;
    if(x*2 == w && y*2 == h)cnt = 1;
    cout << fixed << setprecision(10) << m << " " << cnt << endl;
}