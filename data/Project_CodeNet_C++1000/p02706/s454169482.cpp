/**
*    author:  Taichicchi
*    created: 07.09.2020 21:21:50
**/

#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
typedef long long ll;

int main() {
    ll N, M;
    cin >> N >> M;

    ll s;

    s = 0;

    for(ll i=0;i<M;++i){
        ll a;
        cin >> a;
        s += a;
    }

    if(N < s){
        cout << -1 << endl;
    }else{
        ll ans;
        ans = N-s;
        cout << ans << endl;
    }

    return 0;
}