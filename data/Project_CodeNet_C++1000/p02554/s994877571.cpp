#include<bits/stdc++.h>

#define Bye return 0
#define ll long long

using namespace std;

const int M = 1e9+7;

ll modPow(ll a, ll b){
    ll res = 1;
    a %= M;
    while(b>0){
        if(b&1) res = res * a % M;
        a = a * a % M;
        b >>= 1;
    } return res;
}

ll modSum(ll a, ll b){
    return (a%M+b%M)%M;
}

ll modSub(ll a, ll b){
    return ((a%M)-(b%M)+M)%M;
}

ll modMul(ll a, ll b){
    return ((a%M)*(b%M))%M;
}

void solve(){
    ll n; cin>>n;
    cout<<modSub(modSum(modPow(10, n), modPow(8, n)), modMul(2, modPow(9, n)))<<endl;
}

int main(){
    solve();
    Bye;
}