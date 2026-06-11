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

void solve(long long N, std::vector<long long> A){
    map<ll, ll> CNT;
    set<ll> R;
    set<ll> Test(ALL(A));
    REP(i, N){CNT[A[i]]++;}
    for(auto x: CNT){
        if(x.second == 1) R.insert(x.first);
    }
    ll ans = 0;
    for(ll x: R){
        if( x == 1 ) {ans = 1; break;}
        bool isGood = true;
        for(ll t = 1; t*t <= x; t++){
            if(x % t != 0) continue; // not divisor
            if(Test.count(t)) {isGood = false; break;}
            if(t != 1) {
                if(Test.count(x/t)) {isGood = false; break;}
            }
        }
        if(isGood) ans ++;
    }
    cout<<ans<<endl;
}
int main(){
    long long N;
    scanf("%lld",&N);
    std::vector<long long> A(N);
    for(int i = 0 ; i < N ; i++){
        scanf("%lld",&A[i]);
    }
    solve(N, std::move(A));
    return 0;
}
