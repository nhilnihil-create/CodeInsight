#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
int num=1e9+7;
//繰り返し二乗法
ll ex(ll x,ll n){
    if(n==0)return 1;
    else if(n%2==1)return ex(x,n-1)*x%num;
    else return ex(x*x%num,n/2)%num;
};
//二項係数
ll nikou(ll n,ll k){
    ll dived=1,div=1;
    for(int i=0; i<k; i++){
        dived*=(n-i)%num;dived%=num;
        div*=(i+1)%num;div%=num;
    }
    div=ex(div,num-2);
    return dived*div%num;
};
int main(){
    ll n,k;
    cin >> n >> k;
    for(ll i=1; i<=k; i++){
        ll tmp=nikou(n-k+1,i);
        ll tran=nikou(k-1,i-1);
        ll ans=(tmp*tran)%num;
        cout << ans << endl;
    }
}