#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
    int n;
    cin>>n;
    
    double d=((n+1)/2.0)/n;
    
    if(n%2==1) cout<<fixed<<setprecision(10)<<d<<endl;
    else cout<<fixed<<setprecision(10)<<1/2.0<<endl;
    
    return 0;
}