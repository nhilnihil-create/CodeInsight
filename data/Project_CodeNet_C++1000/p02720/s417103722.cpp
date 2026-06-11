#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <cstdio>
#include <cmath>
#include <queue>

using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
#define rep2(i,n) for(int i=1;i<(n);i++)
typedef long long ll;

ll gcd(ll a, ll b){
    if(a<b) swap(a,b);
    if(a%b == 0) return b;
    else return gcd(b,a%b);
}



int main(){
    queue<ll> que;
    rep2(i,10) que.push(i);
    ll k; cin >> k;
    ll ans = 0;
    while(k>0){
        ans = que.front();
        que.pop();
        k--;

        if(ans % 10 != 0) que.push(10 * ans + ans % 10 - 1);
        que.push(10 * ans + ans % 10);
        if(ans % 10 != 9) que.push(10 * ans + ans % 10 + 1);
    }
    cout << ans << endl;
}