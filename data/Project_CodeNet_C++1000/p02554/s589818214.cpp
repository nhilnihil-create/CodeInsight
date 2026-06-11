#include<iostream>
using namespace std;

typedef long long ll;

const ll mod = 1e9 + 7;

ll pow(ll a, ll x){ // a to the xth power
    if(!x) return 1;
    if(x % 2){
        return pow(a, x / 2) * pow(a, x / 2) % mod * a % mod;
    }
    else{
        return pow(a, x / 2) * pow(a, x / 2) % mod;
    }
}

int main(){
    ll n; cin>>n;
    ll res = (mod * 5 + pow(10, n) - pow(9, n) - pow(9, n) + pow(8, n)) % mod;
    cout<<res<<endl;
}
