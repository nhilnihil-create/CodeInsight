#include <stdio.h>
#include <algorithm>
#include <utility>
#include <functional>
#include <cstring>
#include <queue>
#include <stack>
#include <cmath>
#include <iterator>
#include <vector>
#include <string>
#include <set>
#include <iostream>
#include <random>
#include <map>
#include <iomanip>
#include <stdlib.h>
#include <list>
#include <typeinfo>
#include <list>
#include <set>
#include <cassert>
#include <fstream>
#include <unordered_map>
#include <cstdlib>
#include <complex>
#include <cctype>
#include <bitset>
using namespace std;

using ll = long long;
using vll = vector<ll>;
using pll = pair<ll, ll>;
using qll = queue<ll>;
using vb = vector<bool>;
using mll = map<ll, ll>;
using sll = stack<ll>;
#define REP(i,n) for(ll i(0);(i)<(n);(i)++)
#define rep(i,n) for(ll i(0);(i)<(n);(i)++)
#define ALL(a) a.begin(), a.end()
#define enld endl //* missspell check
const ll INF = 1LL << 60;
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a = b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a = b; return 1; } return 0; }

void solve(long long H, long long W, long long M, std::vector<long long> h, std::vector<long long> w){
    vll sumh(H, 0), sumw(W, 0);
    REP(i, M){
        sumh[h[i]]++;
        sumw[w[i]]++;
    }
    ll maxh = 0, maxw = 0;
    REP(x, H) chmax(maxh, sumh[x]);
    REP(y, W) chmax(maxw, sumw[y]);
    ll cnth = 0, cntw = 0;
    REP(x, H) if(sumh[x]==maxh) cnth++;
    REP(y, W) if(sumw[y]==maxw) cntw++;
    ll ans = maxh + maxw;
    ll cnt = 0;
    REP(i, M) if(sumh[h[i]]==maxh && sumw[w[i]]==maxw) cnt++;
    if(cnt < cnth*cntw) cout<<ans<<endl;
    else cout<<ans-1<<endl;

}
int main(){
    long long H;
    scanf("%lld",&H);
    long long W;
    scanf("%lld",&W);
    long long M;
    scanf("%lld",&M);
    std::vector<long long> h(M);
    std::vector<long long> w(M);
    for(int i = 0 ; i < M ; i++){
        scanf("%lld",&h[i]);
        scanf("%lld",&w[i]);
        h[i]--; w[i]--;
    }
    solve(H, W, M, std::move(h), std::move(w));
    return 0;
}
