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



int main(){
    int n, m;
    cin >> n >> m;
    vector<P> p;
    rep(i, m){
        int a, b;
        cin >> a >> b;
        int s = 0;
        rep(j, b){
            int c;
            cin >> c;
            c--;
            s += 1 << c;
        }
        p.emplace_back(s, a);
    }
    vector<ll> dp(1 << n, INF);
    dp[0] = 0;
    rep(i, 1 << n){
        rep(j, m){
            int t = (i | p[j].first);
            dp[t] = min(dp[t], dp[i] + p[j].second);
        }
    }
  	//rep(i, 1 << n)cout << dp[i] << endl;
  	if(dp[(1 << n) - 1] == INF)cout << -1 << endl;
    else cout << dp[(1 << n) - 1] << endl;
}
