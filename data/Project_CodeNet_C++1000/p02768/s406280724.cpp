#include<bits/stdc++.h>
using namespace std;
using ll = long long;

const int M = 1e9+7;

int mul(int a, int b){
    return (ll)a*b%M;
}

int add(int a, int b){
    return (a+b)%M;
}

int p(int a,int b){
    ll res = 1;
    while(b>0){
        if(b%2) res = mul(res,a);
        a = mul(a,a);
        b/=2;
    }
    return res%M;
}

int self_inv(int a){
    return p(a,M-2);
}

int sub(int a, int b){
    return (a%M - b%M + M)%M;
}

int nck(int n, int k){
    if(n<=0 || k<=0) return 1;
    int res = 1;
    for(int i = n; i>n-k; i--){
        res = mul(res,i);
    }
    int kfact = 1;
    for(int i = k ; i>0; i--){
        kfact = mul(kfact,i);
    }
    return mul(res,self_inv(kfact));
}

int main(){
    ll n,a,b;cin>>n>>a>>b;
    
    ll ans = p(2,n)-1;
    ans = sub(ans,nck(n,a));
    ans = sub(ans,nck(n,b));
    cout<<ans;

}
