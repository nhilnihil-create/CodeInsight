#include <iostream>
using namespace std;
int main(){
    double w, h, x, y;
    cin >> w >> h >> x >> y;
    int f;
    if(w/2.0==x&&h/2.0==y) f=1;
    else f=0;
    double ans = w*h/2.0;
    printf("%.7lf %d\n",ans,f);
    return 0;
}