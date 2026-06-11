#include <bits/stdc++.h>
using namespace std;

int main(){
    cout<<fixed<<setprecision(15);
    double A, B, H, M;
    cin>>A>>B>>H>>M;
    //角度を求めよう
    double X;
    X=H*30+((M/60)*30);
    // cout<<X<<endl;
    // cout<<fixed<<setprecision(15)<<X<<endl;
    double Y;
    Y=M*6;
    // cout<<Y<<endl;
    // cout<<fixed<<setprecision(15)<<Y<<endl;
    double Z;
    Z = X-Y;
    if(Z>180){
        Z=360-Z;
    }
    // cout<<Z<<endl;
    // cout<<fixed<<setprecision(15)<<Z<<endl;
    double S;
    S = sqrt((A*A)+(B*B));
//   cos(3.14159/2);
//   cout<<cos(3.14159/2)<<endl;
   double Q;
   Q = sqrt(((A*A)+(B*B))-(2*A*B*cos(M_PI*Z/180)));
   cout<<Q<<endl;
    
}