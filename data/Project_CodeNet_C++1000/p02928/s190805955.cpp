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



int main(){
    ll n, k;
    cin >> n >> k;
    VEC(ll, a, n);

    vector<P>cnt(n);
    rep(i, n){
        int fst = 0, snd = 0;
        rep(j, n){
            if(j < i){
                if(a[j] < a[i])fst++;
            }
            else if(j == i)continue;
            else{
                if(a[j] < a[i])snd++;
            }
        }
        cnt[i] = P(fst, snd);
    }

    ll res = 0;
    rep(i, n){
        ll fst = cnt[i].first, snd = cnt[i].second;
        ll hoge = ((k + 1) * k / 2) % MOD * snd % MOD;
        res += hoge;
        hoge = (k * (k - 1) / 2) % MOD * fst % MOD;
        res += hoge;
    }
  res %= MOD;
    cout << res;
}