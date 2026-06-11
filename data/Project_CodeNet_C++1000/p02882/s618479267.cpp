#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const long double PI = (acos(-1));

int main(){
    double a, b, x, theata;
    cin>> a >> b >> x;

    if(x > a*a*b/2){
        theata = atan(2*(a*a*b - x)/(a*a*a));
    }else{
        theata = atan((a*b*b)/(2*x));
    }
    theata = theata*180/PI;
    cout<<setprecision(10)<< theata <<endl;
    return 0; 
}