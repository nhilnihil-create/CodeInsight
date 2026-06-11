#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int mod(ll l,ll r){
    int minv = 200000;
    for(ll i=l;i<=r;i++){
        for(ll j=i+1;j<=r;j++){
            //cout << l << " " << r << endl;
            int imod = i % 2019;
            int jmod = j % 2019;
            int p = imod * jmod;
            int mod = p % 2019;
            //printf("%d %d %d\n",imod,jmod,p);
            if(minv > mod){
                minv = mod;
            }
        }
    }
    return minv;
}

int main(){
    ll l,r;
    cin >> l >> r;
    if(l / 2019 != r / 2019){
        cout << 0 << endl;
    }else{
        ll b = mod(l,r);
        cout << b << endl; 
    }
}