#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <iomanip>
using namespace std;
int main(void){
    double xs,ys,xt,yt;
    cin>>xs>>ys>>xt>>yt;
    double dx=xs-xt,dy=ys-yt;
    cout<<fixed<<setprecision(10);
    cout<<sqrt(dx*dx+dy*dy)<<endl;
    
}
