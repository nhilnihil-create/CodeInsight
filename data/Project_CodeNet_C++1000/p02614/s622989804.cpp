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
    int h,w,k,ans=0; cin >> h >> w >> k;
    vector<string> c(h);
    rep(i,h) cin >> c[i];
    rep(is,1<<h)rep(js,1<<w){
        int cnt = 0;
        rep(i,h)rep(j,w){
            if(is>>i&1) continue;
            if(js>>j&1) continue;
            if(c[i][j] == '#') cnt++;
        }
        if(cnt == k) ans++;
    }
    cout << ans << endl;
}