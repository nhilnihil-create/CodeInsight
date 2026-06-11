#include <iostream>
#include <iomanip>
#include <math.h>
using namespace std;
int main(void){
    int n,s[1000],i;
    double a,m;
    while(1){
        cin>>n;
        if(!n) 
           break;
        m=a=0;
        for(i=0;i<n;i++){
            cin>>s[i];
            m+=s[i];
        }
        m/=n;
        for(i=0;i<n;i++){
            a+=(s[i]-m)*(s[i]-m);
        }
        a=sqrt(a/n);
        cout<<fixed<<setprecision(6)<<a<<endl;
    }
}

