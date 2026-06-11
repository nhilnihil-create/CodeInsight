#include <bits/stdc++.h>
using namespace std;
using  LL = long long;
LL yhaa(LL x, LL n, LL mod){
    if (n == 0){
        return 1;
    }
    if (n%2 == 0){
        LL t = (yhaa(x,n/2, mod)) % mod;//???????
        return (t*t) % mod;
    }
    return (x * yhaa(x, n-1, mod)) % mod;
}
 
LL nCk(LL n,LL k,LL m){
    int K;
    if (2*k > n){
        K  = n - k;
    }
    else{
        K = k;
    }
    LL X = 1;
    for(int i = 0; i < K;i++){
        X = (X*(n-i)) % m;
    }
    LL Y = 1;
    for(int i = 1; i < K+1; i++){
        Y = (Y*i) % m;
    }
    LL YY = yhaa(Y,1000000005,m);
    return (X*YY) % m;
 
}
int main(){
    int X, Y;
    cin >> X >> Y;
    int a, b;
    LL ans; 
    ans = 0;
    
    if ((X+Y) % 3 == 0){
        a = (2*X - Y) / 3;
        b = X - 2*a;
        if (a >= 0){
            if(b >= 0){
                ans = nCk(a+b,min(a,b),1000000007);
            }
        }
            
    }
 
    if (ans < 0){
        ans += 1000000009;
    }
    cout << ans << endl;
 
}