#include<bits/stdc++.h> 
using namespace std;
using ll = long long;

#define fast_io ios_base::sync_with_stdio(false) ; cin.tie(0); cout.tie(0);
# define M_PIl          3.141592653589793238462643383279502884L


int main() {
    fast_io;
    long double a,b,h,m;
    cin>>a>>b>>h>>m;
    cout<<fixed<<setprecision(20);

    //double long rad = (abs((h*30)-(m*6)))*(M_PIl/180);
    long double lhand = h*30+m*0.5;
    long double shand = m*6;
    long double rad = abs(lhand-shand);
    rad=rad/180*M_PIl;

    long double ans = sqrt(a*a+b*b-2*a*b*cos(rad));
    cout<<ans<<endl;
}


