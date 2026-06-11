 
 
#include<bits/stdc++.h>
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<string>
 
using namespace std;

 
const int MAX_N = int(1e6) + 10;
const long long int MOD=1e9+7;
const long long int INF=1e18;
 
typedef long long int ll;
typedef unsigned long long int llu;
 
 
 
inline ll mul(ll a,ll b){
 
    a=(a+MOD)%MOD;
    b=(b+MOD)%MOD;
    ll c=a*b;
    c=(c+MOD)%MOD;
    return c;
}
inline ll add(ll a,ll b){
    a=(a+MOD)%MOD;
    b=(b+MOD)%MOD;
    ll ans=(a+b);
    ans=(ans+MOD)%MOD;
    return ans;
}
ll power(ll a,ll b,ll c=0){
    ll ans=1;
    while(b){
        if(b&1){
            ans=mul(ans,a);
        }
        a=mul(a,a);
        b=b/2;
    }
    return ans;
}
 
  
 
 
#define all(x) (x).begin(),(x).end()




//s.reserve(32768); //updated !
//s.max_load_factor(0.25);











ll fact[1000005];
ll inv[1000005];


inline ll fun(ll x,ll y){
    return mul(mul(fact[x],inv[x-y]),inv[y]);
}

int main(){

    int n;
    cin>>n;
    int g=__gcd(360,n);
    cout<<360/g<<endl;
   
   
   
    
}


 
    



    



    
    
    




    


    

    






    
    

    
 
    
 

 
 
    
 
 
