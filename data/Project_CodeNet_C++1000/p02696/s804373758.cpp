#include<bits/stdc++.h>
#define ll long long int
using namespace std ;
int main(){
    ll a,b,n; 
    cin>>a>>b>>n; 
    ll x=n;
    if(n>=b-1){
        x=b-1; 
    }
    ll r=(a*x)/b-a*(x/b) ; 
    cout<<r<<endl; 
    return 0; 
}
    
    
    