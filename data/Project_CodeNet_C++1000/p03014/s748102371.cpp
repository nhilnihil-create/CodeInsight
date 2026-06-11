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
#define fi first
#define se second
using pint = pair<int,int>;
using vec = vector<int>;
using ll=long long;
using vll = vector<ll>;
using vvll = vector<vector<ll>>;
//---------------------------------------------------------------
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};
//---------------------------------------------------------------

//↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓
    ll l[2005][2005]; ll r[2005][2005];ll u[2005][2005]; ll d[2005][2005];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int h,w;
    cin>>h>>w;
    vector<string> fi(h);    
    rep(i,h){
        cin>>fi[i];
    }

    rep(i,h){
        int cur = 0;
        rep(j,w){
            if(fi[i][j]=='#') cur=0;
            else cur++;
            l[i][j]=cur;
        }
    }

    rep(i,h){
        int cur = 0;
        for(int j=w-1; j>=0; j--){
            if(fi[i][j]=='#') cur=0;
            else cur++;
            r[i][j]= cur;
        }
    }    

    rep(j,w){
        int cur = 0;
        rep(i,h){
            if(fi[i][j]=='#') cur=0;
            else cur++;
            u[i][j]=cur;
        }
    }   

    rep(j,w){
        int cur = 0;
        for(int i=h-1; i>=0; i--){
            if(fi[i][j]=='#') cur=0;
            else cur++;
            d[i][j]=cur;
        }
    }

    ll ans=0;
    rep(i,h)rep(j,w){
        if(fi[i][j]=='#') continue;
        ans=max(ans,l[i][j] + r[i][j] + u[i][j] + d[i][j] - 3);
    }

    cout << ans <<endl;

    return 0;
}