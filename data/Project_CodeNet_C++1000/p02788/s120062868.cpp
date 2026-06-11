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
#define chmin(a, b) a = min(a, b)


using namespace std;
using ll = long long;
using Graph = vector<vector<int>>;
using P = pair<ll, ll>;




int main(){
    ll n, dist, atk;
    cin >> n >> dist >> atk;

    vector<P> p;
    rep(i, n){
        ll x, h;
        cin >> x >> h;
        p.emplace_back(x, h);
    }
    sort(ALL(p));

    ll res = 0;
    ll tot = 0;
    queue<P> que;
    rep(i, n){
        ll x = p[i].first, h = p[i].second;
        while(!que.empty() && que.front().first < x){
            tot += que.front().second;
            que.pop();
        }

        h = max(h - tot, (ll)0);
      //cout << h << endl;
        ll a = h / atk + (h % atk == 0 ? 0 : 1);
        res += a;
        tot += a * atk;
        que.emplace(x + 2 * dist, -a * atk);
    }
    cout << res << endl;
}
