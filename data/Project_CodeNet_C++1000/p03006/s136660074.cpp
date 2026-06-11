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
#define elnd endl //* missspell check
const ll INF = 1LL << 60;


void solve(long long N, std::vector<long long> x, std::vector<long long> y){
    vector<pll> pt(N);
    REP(i, N) {
        pt[i].first = x[i];
        pt[i].second = y[i];
    }
    ll ans = N;
    REP(i, N-1){
        for(ll j=i+1; j < N; j++){
            ll p = x[j]-x[i], q = y[j]-y[i];
            ll cnt = 0;
            set<pll> tmp(pt.begin(), pt.end());
            while(!tmp.empty()){
                ll refx = tmp.begin()->first, refy = tmp.begin()->second; 
                cnt ++;
                tmp.erase(tmp.begin());
                if(tmp.empty())
                    break;
                for(auto it = tmp.begin(); it != tmp.end(); ){
                    if(it->first - refx == p && (it->second - refy) == q){
                        refx = it->first; refy = it->second;
                        it = tmp.erase(it);
                    }
                    else{
                        ++it;
                    }
                }
            }
            ans = min(ans, cnt);
        }
    }
    cout << ans << endl;
}

int main(){
    long long N;
    scanf("%lld",&N);
    std::vector<long long> x(N);
    std::vector<long long> y(N);
    for(int i = 0 ; i < N ; i++){
        scanf("%lld",&x[i]);
        scanf("%lld",&y[i]);
    }
    solve(N, std::move(x), std::move(y));
    return 0;
}
