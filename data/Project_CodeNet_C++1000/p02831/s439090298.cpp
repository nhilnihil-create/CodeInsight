#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);i++)
using ll=long long;
using namespace std;

ll gcd(ll a,ll b){return(a%b)?gcd(b,a%b):b;}

ll lcm(ll a,ll b){return(a*b/gcd(a,b));}

int main(){
    ll a,b;
    cin>>a>>b;
    
    cout<<lcm(a,b)<<endl;
    return 0;
}