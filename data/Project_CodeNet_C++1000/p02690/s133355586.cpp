#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define rep(i,n) for(ll i = 0;i < n;++i)

int main(){
    ll x;
    cin >> x;
    ll a,b;
    rep(i,150){
        rep(j,150){
            a = pow(i,5);
            b = pow(j,5);
            if(a+b == x){ 
                cout << i << " -" << j << endl;
                return 0;
            }else if(a-b == x){
                cout << i << " " << j << endl;
                return 0;
            }
        }
    }
    return 0;
}