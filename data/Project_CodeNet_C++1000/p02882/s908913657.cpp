#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout<<setprecision(15);

    //I don't care about anybody, and fuck ratings! I'll go to google!
    int a, b, x; cin>>a>>b>>x;

    long double y;
    if(2*x > a*a*b) y = atan((2.0*a*a*b - 2.0*x)/(1.0*a*a*a));
    else y = atan((1.0*a*b*b)/(2.0*x));
    y = y*180.0/M_PI;
    cout<<y<<"\n";
    return 0;
}
