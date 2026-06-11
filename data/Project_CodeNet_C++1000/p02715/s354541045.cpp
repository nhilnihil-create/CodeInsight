//
//  main.cpp
//  E
//
//  Created by 曾憲揚 on 2020/8/21.
//  Copyright © 2020 曾憲揚. All rights reserved.
//

#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5+5;
const int MOD = 1e9+7;
int Gcd[maxn];

int mul(int a, int b){
    return (1LL*a*b)%MOD;
}
int quickpow(int a, int pow){
    int ans = 1;
    while(pow>0){
        if(pow&1) ans = mul(ans, a);
        a = mul(a, a);
        pow>>=1;
    }
    return ans;
}

int main(int argc, const char * argv[]) {
    int n, k; cin>>n>>k;
    for(int i=k; i>0; i--){
        Gcd[i] = quickpow(k/i, n);
        for(int j=i+i; j<=k; j+=i){
            Gcd[i] -= Gcd[j];
            if(Gcd[i]<0) Gcd[i] += MOD;
        }
    }
    int ans=0;
    for(int i=1; i<=k; i++){
        ans = (ans + mul(Gcd[i], i))%MOD;
    }
    cout<<ans<<endl;
    return 0;
}
