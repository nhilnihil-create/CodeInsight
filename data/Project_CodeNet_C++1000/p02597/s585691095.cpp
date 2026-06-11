#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <cstdio>
#include <cmath>

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
    int n;
    string x;
    cin >> n >> x;
    int rcnt = 0, ans = 0;
    rep(i,n){
        if(x[i] == 'R') rcnt++;
    }
    ans = rcnt;
    int wcnt = 0;
    int now = rcnt;
    rep(i,n){
        if(x[i] == 'R') rcnt--;
        else wcnt++;

        now = max(rcnt,wcnt);
        if(now < ans) ans = now;
    }
    cout << ans << endl;
}