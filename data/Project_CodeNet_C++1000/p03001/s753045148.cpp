#include<bits/stdc++.h>
using namespace std;

int main(){
    double w, h, x, y;
    cin >> w >> h >> x >> y;
    double ans = w *h /2;
    printf("%.6f ", ans);
    if(2*x==w && 2*y==h) printf("1\n");
    else printf("0\n");
    return 0;
}