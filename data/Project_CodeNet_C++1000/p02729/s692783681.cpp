//Moh_K_Imar .......
//22/08/2020  ... 12,35 .
//Ya Rab....
#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using ld=long double;
int main(){
    ll a,b;
    cin>>a>>b;
    ll res=0,sum=0;
    for(ll i=a-1;i>0;i--){
        sum+=i;
        a--;
    }
    for(ll i=b-1;i>0;i--){
        res+=i;
        b--;
    }
    cout<<sum+res<<endl;
    sum=0,res=0;
  
    return 0;
}

