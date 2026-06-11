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
#include <cassert>
#include <cmath>
#include<cstdint>

#define INF 1e9
#define rep(i,n)for(int i=0;(i)<(int)(n);i++)
#define REP(i,a,b)for(int i=(int)(a);(i)<=(int)(b);i++)
#define VEC(type, c, n) std::vector<type> c(n);for(auto& i:c)std::cin>>i;
#define vec(type,n) vector<type>(n)
#define vvec(m,n) vector<vector<int>> (int(m),vector<int>(n))
#define ALL(a)  (a).begin(),(a).end()


using namespace std;
using ll = long long;
using Graph = vector<vector<int>>;
using P = pair<ll, ll>;

const ll MOD = INF + 7;

ll mpow(ll x, ll n){
    ll ans = 1;
    while(n != 0){
        if(n & 1)ans = ans * x % MOD;
        x = x * x % MOD;
        n = n >> 1;
    }
    return ans;
}

int main(){
    int n;
    cin >> n;
    vector<map<int, int>> bit_cnt(60);
    rep(i, n){
        ll a;
        cin >> a;
        rep(j, 60){
            if(a & 1)bit_cnt[j][1]++;
            else bit_cnt[j][0]++;

            a = a >> 1;
        }
    }

    
    ll res = 0;

    rep(i, 60){
        res += mpow(2, i) * bit_cnt[i][0] % MOD * bit_cnt[i][1] % MOD;
        res %= MOD;
    }
    cout << res << endl;
}


