#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
const ll mod = 1e9+7;

//繰り返し二乗法
ll ex(ll x,ll n){
    if(n==0)return 1;
    else if(n%2==1)return ex(x,n-1)*x%mod;
    else return ex(x*x%mod,n/2)%mod;
};

//二項係数
ll nikou(ll n,ll k){
    ll dived=1,div=1;
    for(int i=0; i<k; i++){
        dived*=(n-i)%mod;dived%=mod;
        div*=(i+1)%mod;div%=mod;
    }
    div=ex(div,mod-2);
    return dived*div%mod;
};

int main(){
    int n;
    cin >> n;
    int a,b;
    cin >> a >> b;
    cout << (ex(2,n)-1-(nikou(n,a)+nikou(n,b))%mod+mod)%mod << endl;
    return 0;
}