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
#define INF 1000000000000000000ll
#define all(x) x.begin(),x.end()
#define fi first
#define se second
using pint = pair<int,int>;
using vec = vector<int>;
using ll = long long;
using vll = vector<ll>;
using vvll = vector<vector<ll>>;
//---------------------------------------------------------------
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};
const double pi = acos(-1);
//---------------------------------------------------------------

//↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    ll n;;
    cin>>n;
    vll a(n);
    vll cnt(200001,0);
    ll ans=0;
    rep(i,n){
        cin>>a[i];
        cnt[a[i]]++;
    }
    auto c = a;
    sort(all(a));
    ans = a[n-1];

    rep(i,n){
        if(ans>c[i]){
            cout<<ans<<endl;
        }else if(ans==c[i]){
            if(cnt[c[i]]>=2) cout<<ans<<endl;
            else cout<<a[n-2]<<endl;   
        }
    }
}