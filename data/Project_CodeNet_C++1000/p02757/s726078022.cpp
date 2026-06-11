//
//  main.cpp
//  atcoder
//
//  Created by Hisaki Kobayashi on 2020/04/14.
//  Copyright © 2020 Hisaki Kobayashi. All rights reserved.
//

#include <bits/stdc++.h>
#include <string>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <bitset>
typedef long long ll;
using namespace std;

const int MAX = 510000;
const int MOD = 1000000007;
const int MAX_N = 200000;

int ctoi(const char c){
  switch(c){
    case '0': return 0;
    case '1': return 1;
    case '2': return 2;
    case '3': return 3;
    case '4': return 4;
    case '5': return 5;
    case '6': return 6;
    case '7': return 7;
    case '8': return 8;
    case '9': return 9;
    default : return -1;
  }
}

int main(int argc, const char * argv[]) {
    
    ll N,P;cin >> N >> P;
    string S;
    cin >> S;
    
//    reverse(S.begin(),S.end());
    
    vector<ll> d(N);
    for(ll i=0;i<N;i++){
        d[i] = ctoi(S[N-i-1]);
    }
    
    if(10%P==0){
        ll ans=0;
        for(ll i=0;i<N;i++){
            if(d[i]%P==0){
                ans += N-i;
            }
        }
        cout << ans << endl;
        return 0;
    }

    vector<ll> s(N+1);
    s[0] = 0;
    
    ll ten=1;
    for(ll i=0; i<N; i++){
        
        s[i+1] = (ten * d[i] + s[i])%P;
//        ten *= 10 % P;
        ten = ten*10% P;
    }
    
    vector<ll> kind(P,0);
    
    for(ll i=0;i<N+1;i++){
        kind[s[i]]++;
    }
    
    
    ll cnt=0;
    for(ll i=0;i<P;i++){
        cnt += ((kind[i]-1)*(kind[i]))/2;
    }

    cout << cnt << endl;
    
    return 0;
}


