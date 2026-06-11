//
//  main.cpp
//  D
//
//  Created by 曾憲揚 on 2020/8/19.
//  Copyright © 2020 曾憲揚. All rights reserved.
//

#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9+7;
typedef long long ll;


int main(int argc, const char * argv[]) {
    ll n, k; cin>>n>>k;
    ll ans = 0;
    for(ll i=k; i<=n+1; i++){
        ll s= (i-1)*i/2; ll t=(n+n-i+1)*i/2;
        ans += (t-s+1);
        ans%=MOD;
    }
    cout<<ans<<endl;
    return 0;
}
