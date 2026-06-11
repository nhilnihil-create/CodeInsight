#include<bits/stdc++.h>

using namespace std;

int main(){
    int l;
    cin>>l;
    double a,b;
    
    a=l/3.0;
    b=l-2*a;
    
    cout<<fixed<<setprecision(10)<<a*a*b<<endl;
}