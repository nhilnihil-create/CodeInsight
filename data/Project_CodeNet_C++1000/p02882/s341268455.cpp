#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0; i<(n); i++)
#define ALL(n) begin(n),end(n)
const double pi=acos(-1);
 
int main(){
    long double a,b,x;
    cin>>a>>b>>x;
    
    if(x/a>a*b/2){
        cout<<setprecision(10)<<atan(-2*(x-a*a*b)/pow(a,3))*180/pi<<endl;
    }else{
        cout<<setprecision(10)<<atan(a*b*b/(2*x))*180/pi<<endl;
    }
}