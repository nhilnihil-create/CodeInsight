#include <bits/stdc++.h>
#include <string>
using namespace std;
typedef long long ll;

ll mod=998244353;
double PI=3.14159265358979323846;
int main(){
    double a,b,x;
    cin>>a>>b>>x;
    
    x/=a;
    
    double deg=atan(b/a);
    if(a*b/2>x){
        double aa=x*2/b;
        deg=atan(b/aa);
    }else{
        double bb=(a*b-x)*2/a;
        deg=atan(bb/a);
    }
    
    cout<<fixed<<setprecision(20)<<deg*180.0/PI<<endl;
}