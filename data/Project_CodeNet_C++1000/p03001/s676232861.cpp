#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    ll w,h,x,y;
    int flag = 0;
    cin >> w >> h >> x >> y;
    double max = w * h / 2.0;
    if(2*x == w && 2*y == h){
        flag = 1;
    }
    printf("%.10lf %d",max,flag);
}