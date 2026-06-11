#include<bits/stdc++.h>

using namespace std;
using ll = long long;
const int nax = 1e6+1;
using dl = long double;
const dl PI = 3.14159265358979323846264;
int main(){
   dl a,b,x;
   cin>>a>>b>>x;
    dl vol =a*a*b;
    dl k= a*a*a;
if(x>=vol/2){
   dl z= vol - x;
   z= 2*z;
   dl p = z/k;
    dl ret = atan(p);
    dl val = (ret * 180) / PI;
    cout<<fixed<<setprecision(12)<<val;
}
else{
    dl q = b*b*a;
    q/=2;
    q/=x;
    dl ret = atan(q);
     dl val = (ret * 180) / PI;
    cout<<fixed<<setprecision(12)<<val;



}
return 0;
}

