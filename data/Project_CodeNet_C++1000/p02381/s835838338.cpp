#include<iostream>
#include<math.h>
#include<iomanip>
using namespace std;
int main(){
    int n;
    double a[1001],s,e;
    do{
    cin >>n;
    if(n==0)
        break;
    s=0;
    e=0;
    for(int i=0;i<n;i++)  
    {
        cin >>a[i];
        s+=(a[i]/n);
    }
    for(int i=0;i<n;i++){
      e+=((a[i]-s)*(a[i]-s))/n;  
    }
    cout<<fixed;
    cout <<setprecision(8)<<sqrt(e)<<endl;}while(true);
    return 0;
}