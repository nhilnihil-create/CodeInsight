#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
typedef long long ll;
const ll M=1000000007;
//------------------------------------------//
ll f(ll n){
    return n*n*n*n*n;
}
int main(){
    ll X;cin>>X;
    for(int a=-120;a<=120;a++){
        for(int b=-120;b<=120;b++){
            if(X==f(a)-f(b)){
                cout<<a<<' '<<b<<endl;
                return 0;
            }
        }
    }
}
