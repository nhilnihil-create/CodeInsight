#include <iostream>
#include <cstdio>
using namespace std;
int main(){
    int w,h,x,y;
    cin >> w >> h >> x >> y;
    int a = 0;
    if(w%2 == 0 && h%2 == 0){
        if(w/2 == x && h/2 == y) a = 1;
    }  
    double ans = (double)w*h/2.0;
    printf("%.10f %d\n", ans, a);
    return 0;
}