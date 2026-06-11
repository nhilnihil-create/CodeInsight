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

ll getMin(ll h, ll m){return h*60+m;}

void solve(std::vector<long long> H, std::vector<long long> M, long long K){
    ll T0 = getMin(H[0], M[0]);
    ll T1 = getMin(H[1], M[1]);
    cout<<(T1-T0)-K<<endl;
}
int main(){
    std::vector<long long> H(2);
    std::vector<long long> M(2);
    for(int i = 0 ; i < 2 ; i++){
        scanf("%lld",&H[i]);
        scanf("%lld",&M[i]);
    }
    long long K;
    scanf("%lld",&K);
    solve(std::move(H), std::move(M), K);
    return 0;
}
