#include<iostream>
using namespace std;
using ll=long long;
ll MOD=1e9+7;

ll mod_pow(ll a,ll n){
    ll ret=1;
    while(n>0){
        if(n & 1){
            ret=ret*a%MOD;
        }
        a=a*a%MOD;
        n>>=1;
    }
    return ret;
}
ll mod_inv(ll x){
    return mod_pow(x,MOD-2);
}
int main(){
    ll N,A,B;
    cin>>N>>A>>B;
    ll sum=mod_pow(2,N)-1;
    ll bunbo=1;
    ll bunshi=1;
    for(int i=0;i<A;i++){
        bunshi*=N-i;
        bunshi%=MOD;
        bunbo*=i+1;
        bunbo%=MOD;
    }
    bunbo=mod_inv(bunbo);
    sum-=(bunshi*bunbo)%MOD;
    if(sum<0){
        sum+=MOD;
    }
    bunbo=1;
    bunshi=1;
    for(int i=0;i<B;i++){
        bunshi*=N-i;
        bunshi%=MOD;
        bunbo*=i+1;
        bunbo%=MOD;
    }
    bunbo=mod_inv(bunbo);
    sum-=(bunshi*bunbo)%MOD;
    if(sum<0){
        sum+=MOD;
    }
    cout<<sum<<endl;
    return 0;
}