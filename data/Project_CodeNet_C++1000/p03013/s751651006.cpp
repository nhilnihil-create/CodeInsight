#include<iostream>
#include<stdio.h>
//#include <bits/stdc++.h>
#include<vector>
#include<float.h>
#include<iomanip>
#include<algorithm>
#include<string>
#include<cstring>
#include<math.h>
#include<cmath>
#include<sstream>
#include<set>
#include<map>
#include<queue>
#include<cassert>
#include<cmath>
#include<cstdint>


     
#define INF 1e9
#define LINF 1e19
#define rep(i,n)for(int i=0;(i)<(int)(n);i++)
#define REP(i,a,b)for(int i=(int)(a);(i)<=(int)(b);i++)
#define VEC(type, c, n) std::vector<type> c(n);for(auto& i:c)std::cin>>i;
#define vec(type,n) vector<type>(n)
#define vvec(m,n) vector<vector<int>> (int(m),vector<int>(n))
#define ALL(a)  (a).begin(),(a).end()
#define chmin(a, b) a = min(a, b)
#define chmax(a, b) a = max(a, b)
     
using namespace std;
using ll = long long;
using Graph = vector<vector<int>>;
using P = pair<ll, ll>;
     
const ll MOD = 1e9 + 7;
const ll ZER = 0;


ll dp[100100];
int main(){
    ll n, m;
    cin >> n >> m;
    vector<int> a(100100, 0);
    rep(i, m){
        ll tmp;
        cin >> tmp;
        a[tmp] = 1;
    }
    dp[0] = 1;
    rep(i, n){
        if(a[i] == 1)continue;
        dp[i] %= MOD;
        if(a[i + 1] != 1)(dp[i + 1] += dp[i]) % MOD;
        if(a[i + 2] != 1)(dp[i + 2] += dp[i]) % MOD;
        dp[i + 1] %= MOD;
        if(dp[i + 1] < 0)dp[i + 1] += MOD;
        dp[i + 2] %= MOD;
        if(dp[i + 2] < 0)dp[i + 2] += MOD;
    }
    dp[n] %= MOD;
    cout << dp[n] << endl;
}



