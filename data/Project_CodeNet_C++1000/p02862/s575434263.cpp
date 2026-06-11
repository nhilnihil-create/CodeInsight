#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod=1e9+7;
const int nmax=1000010;
ll fact[nmax],finv[nmax],inv[nmax];
 
void inicom(){
    fact[0]=fact[1]=1;
    finv[0]=finv[1]=1;
    inv[1]=1;
    for (int i = 2; i < nmax; i++){
        fact[i]=fact[i-1]*i%mod;
        inv[i]=mod-inv[mod%i]*(mod/i)%mod;
        finv[i]=finv[i-1]*inv[i]%mod;
    }
}
ll com(int n,int k){
    if(n<k||n<0||k<0) return 0;
    return fact[n]*(finv[k]*finv[n-k]%mod)%mod;
}


int main(){
    inicom();
    int X,Y; cin>>X>>Y;
    if((X+Y)%3!=0){
        cout<<0<<endl;
        return 0;
    }
    ll n=(2*Y-X)/3,m=(2*X-Y)/3;
    cout<<com(n+m,n)<<endl;
}