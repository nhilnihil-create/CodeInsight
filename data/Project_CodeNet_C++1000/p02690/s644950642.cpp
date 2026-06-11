#include "bits/stdc++.h"
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
#define vi vector<int>
typedef long long ll;

ll p5(ll x){
    return x*x*x*x*x;
}

signed main(){
    ll x;cin>>x;
    for(ll a=-1000;a<=1000;a++){
        for(ll b=-1000;b<=1000;b++){
            ll res=p5(a)-p5(b);
            if(res==x){
                cout<<a<<' '<<b<<endl;
                return 0;
            }
        }
    }
}