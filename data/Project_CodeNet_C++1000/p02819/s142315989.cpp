#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);i++)
using namespace std;
using ll = long long;
int main(void){
    ll X;
    cin>>X;
    bool Pnum=false;
    bool mod0;
    ll ans;
    while(Pnum==false){
        mod0=false;
        if(X==2){
            ans=X;
            Pnum=true;
        }
        else {
        for(int i=2;i<X;i++){
            if(X%i==0){
                mod0=true;
                X++;
                break;
            }
        }
        }
        if(mod0==false){
            Pnum=true;
            ans=X;
        }
    }
    cout<<ans<<endl;
    }
    
    

