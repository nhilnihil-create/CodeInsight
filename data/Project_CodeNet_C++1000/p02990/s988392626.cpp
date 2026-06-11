#include <iostream>
#include <stdio.h>
#include <bits/stdc++.h>
#include <math.h>
#define ll long long
using namespace std;
#define N 100009
#define mod 1000000007

long long modinv(long long a, long long m) {
    long long b = m, u = 1, v = 0;
    while (b) {
        long long t = a / b;
        a -= t * b; swap(a, b);
        u -= t * v; swap(u, v);
    }
    u %= m;
    if (u < 0) u += m;
    return u;
}

int main(){
    ll num[2001];
    num[0]=1;
    for (int i=1; i<=2000; i++){
        num[i]=num[i-1]*i;
        num[i]%=mod;
    }
    
    int n,k;
    cin>>n>>k;
    
    if (k<=n-k+1){
        for (int i=1; i<=k; i++){
            ll p=num[n-k-i+1]*num[i];
            p%=mod;
            p*=num[k-i];
            p%=mod;
            p*=num[i-1];
            p%=mod;
        
            ll q=num[n-k+1]*num[k-1];
            q%=mod;
        
            ll r=q*modinv(p,mod);
        
            cout<<r%mod<<endl;
        }
    }
    else{
        for (int i=1; i<=n-k+1; i++){
            ll p=num[n-k-i+1]*num[i];
            p%=mod;
            p*=num[k-i];
            p%=mod;
            p*=num[i-1];
            p%=mod;
        
            ll q=num[n-k+1]*num[k-1];
            q%=mod;
        
            ll r=q*modinv(p,mod);
        
            cout<<r%mod<<endl;
        }
        for (int i=n-k+2; i<=k; i++){
            cout<<"0"<<endl;
        }
    }
}