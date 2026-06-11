//---------------------------------------------------------------
#include <bits/stdc++.h>
using namespace std;
#include <iostream>
#include <vector>
#include <cstdlib>
#include <cmath>
#include <math.h>
#include <sstream>
#include <numeric>
#include <cctype>
#include <bitset>
#include <cassert>
#include<algorithm>
//---------------------------------------------------------------
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep1(i, n) for (int i = 1; i <= (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
#define SIZE 100005
#define INF 1000000000000000LL
#define all(x) x.begin(),x.end()
using pint = pair<int,int>;
using vec = vector<int>;
using ll=long long;
using vll = vector<ll>;
using vvll = vector<vector<ll>>;
//---------------------------------------------------------------
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
//---------------------------------------------------------------

//↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓

ll GCD(ll a, ll b){
    ll s = a, t = b;
    while(s%t != 0){
        ll u = s%t;
        s=t; t=u;
    }
    return t;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    ll n,m;cin>>n>>m;
    vll a(n);
    rep(i,n) {cin>>a[i];}
    vll b(n,0);
    auto c = a;
    for(int i=0; i<n; i++){
        while(c[i]%2==0){
            c[i]/=2;
            b[i]++;
        }
    }

    rep(i,n) a[i]/=2;

    bool ok = false;
    rep(i,n-1){
        if(b[i]!=b[i+1]) ok = true;
    }

    if(ok){
        cout<<'0'<<endl;
        return 0;
    }else{
        
        ll t=1;
        rep(i,n){
            ll g = GCD(t, a[i]);
            t = t/g*a[i];
            if(t > m){
                cout<<0<<endl;
                return 0;
            }
        }

        if(t<=m){
        ll ans = 1;
        ll cnt = 0;
        while(true){
            cnt++;
            ll T;
            T = t*ans;
            if(T>m){
                cnt--;
                break;
            }
            if(T==m) break;
            ans+=2;
        }

        cout<<cnt<<endl;
        return 0;

    }
    }
}