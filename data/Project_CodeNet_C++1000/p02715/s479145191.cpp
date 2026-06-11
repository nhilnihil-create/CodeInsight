#include<bits/stdc++.h>
using namespace std;

long long pw[20], ret, f[100069];
long long mod = 1e9+7;
long long pwr(long long x, long long y){
    pw[0]=x;
    for(int i=1; i<20; i++){
        pw[i]=(pw[i-1]*pw[i-1])%mod;
    }
    x=0;
    ret = 1;
    while(y>0){
        if(y%2==1){
            ret = (ret*pw[x])%mod;
        }
        x++;
        y = y/2;
    }
    return ret;
}

int main(){
    long long n, k;
    cin >> n >> k;
    f[k] = 1;
    for(int i=k-1; i>0; i--){
        f[i] = pwr((k/i), n);
        for(int j=2; j*i<=k; j++){
            f[i] = (f[i]+mod-f[j*i])%mod;
        }
    }
    long long ans=0;
    for(int i=1; i<=k; i++){
        ans = (ans + i*f[i])%mod;
    }
    cout << ans << endl;
}
