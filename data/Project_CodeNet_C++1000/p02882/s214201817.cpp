#include <bits/stdc++.h>
#define rep(i,n) for (int i=0; i < (n); i++)
using namespace std;
using ll = long long;

int main(){
    double a,b,x; cin>>a>>b>>x;
    
    //半分より多く入っている
    double ans=0;
    if(pow(a,2)*b <= 2*x){
        ans = atan((2*(a*a*b - x))/(a*a*a));
    }else{
        ans = -(atan((2*x)/(a*b*b)) - M_PI/2);
    }
    cout << fixed << setprecision(15) << ans*(180/M_PI) << endl;
    
}
