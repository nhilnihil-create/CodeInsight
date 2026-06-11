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
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep1(i, n) for (int i = 1; i <= (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
#define SIZE 100005
using pint = pair<int,int>;
using vec = vector<int>;
using ll=long long;
using vll = vector<ll>;
using vvll = vector<vector<ll>>;
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n,m;cin>>n>>m;
    vec br(n);
    rep(i,m) {int a;cin>>a; br[a]=1;}

    vec dp(n+2);
    const int mod=1000000007;
    dp[n]=1;
    for(int i=n-1; i>=0; i--){
        if(br[i]){
            dp[i]=0;
            continue;
        }

        dp[i]=(dp[i+1]+dp[i+2])%mod;

    }

    cout<<dp[0]<<endl;
}