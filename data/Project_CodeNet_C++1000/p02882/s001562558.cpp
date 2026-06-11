#include<bits/stdc++.h>
using namespace std;
const long double PI = (acos(-1));
const long double EPS = 0.0000000001;

long double a, b, x; 


int main(){
    cin >> a >> b >> x;

    long double tan = (2*(a*a*b - x)) / (a*a*a);
    long double thita = 0.0;

    if(a*a*b/2.0 <= x){
        thita = PI/2 - atan(1.0/tan);
    }else{
        thita = PI/2 - atan(2*x / (a*b*b));
    }
    thita = thita*360/(2*PI);
    cout << fixed << setprecision(10) <<  thita << endl;
    return 0;
}