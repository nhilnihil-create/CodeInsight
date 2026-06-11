#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <bitset>
#include <cmath>
#define rep(i,n) for(int i=0;i<(n);++i)

using namespace std;

typedef long long ll;


int main(){
    ll L,R;
    cin>>L>>R;
    
    ll arr[2019];
    
    ll limit=2019<=R-(L-1)?2019:R-(L-1);
    
    limit=limit;

    //cout<<"limit:"<<limit<<endl;

    for(ll i=L;i<limit+L;++i){
        arr[i-L]=i%(ll)2019;
    }

  /*  
     for(ll i=0;i<limit;++i){
     cout<<i<<":"<<arr[i]<<" ";
     }
     cout<<endl;
  */  
    //cout<<"abc"<<endl;
     
    ll ans=2019;
    
    for(ll i=0;i<limit-1;++i){
        for(ll j=i+1;j<limit;++j){
           ll tmp=(arr[i]*arr[j])%2019;
           ans=ans<=tmp?ans:tmp;
        }
    }
    
    cout<<ans<<endl;
}
