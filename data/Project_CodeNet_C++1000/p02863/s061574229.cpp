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
#define chmax(a, b) a = max(a, b)


using namespace std;
using ll = long long;
using Graph = vector<vector<int>>;
using P = pair<ll, ll>;


ll dp[3005][6005];

int main(){
    int n, T;
    cin >> n >> T;
    vector<P> p;
    rep(i, n){
        ll a, b;
        cin >> a >> b;
        p.emplace_back(a, b);
    }
	sort(ALL(p));
    ll res = 0;
    rep(i, n){
        rep(t, T){
            chmax(dp[i + 1][t], dp[i][t]);
            int nt = t + p[i].first;
            if(nt < T)chmax(dp[i + 1][nt], dp[i][t] + p[i].second);
        }
        ll now = dp[i][T - 1] + p[i].second;
        chmax(res, now);
    }
    cout << res << endl;
    //REP(i, 1, n){REP(t, 1, T)cout << dp[i][t] << " ";cout << endl;}
}
