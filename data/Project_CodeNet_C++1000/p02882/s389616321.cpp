#include "bits/stdc++.h"
#define rep(i,n) for (int i=0; i<(n); ++i)
using namespace std;
using ll =long long;
using P =pair<int,int>;

int main(){
    int a,b,x;
    cin >> a >> b >> x;
    int s;
    double the;
    double pi;
    the=0;
    pi=acos(-1);
    s=a*a*b;
    if(2*x>=s){
        the=atan(double(2*(s-x))/double(a*a*a));
        the*=(180.0/pi);
    }
    else{
        the=atan(double(a*b*b)/double(2*x));
        the*=(180.0/pi);

    }



    printf("%.10f",the);
    

    return 0;
}