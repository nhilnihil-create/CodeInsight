#include<bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main(){
    double x1,y1,x2,y2;
    cin>>x1>>y1>>x2>>y2;
    double L;
    double a;
    a = pow(x2-x1, 2)+pow(y2-y1, 2);
    L=pow(a, 1/2.0);
    cout<<fixed<<setprecision(10)<<L<<endl;
    return 0;
}
