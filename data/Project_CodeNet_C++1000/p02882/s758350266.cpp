#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>
#include <map>
#include <iomanip>
#define ll long long
using namespace std;
const double PI=3.14159265;
double todeg(double rad){
    return rad/PI*180.0;
}
int main(){
    double a,b,x;
    cin>>a>>b>>x;
    if(2*x<=a*a*b){
        cout<<fixed<<setprecision(10)<<90.0-todeg(atan(2*x/a/b/b));
    }else{
        cout<<fixed<<setprecision(10)<<todeg(atan(2*(b/a-x/a/a/a)));
    }    
    return 0;
}
