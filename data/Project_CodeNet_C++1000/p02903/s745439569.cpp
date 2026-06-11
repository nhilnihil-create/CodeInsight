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


void solve(long long H, long long W, long long A, long long B){
    REP(i, B){
        REP(j, A) cout<<0;
        REP(j, W-A) cout<<1;
        cout<<endl;
    }
    REP(i, H-B){
        REP(j, A) cout<<1;
        REP(j, W-A) cout<<0;
        cout<<endl;
    }
}

int main(){
    long long H;
    scanf("%lld",&H);
    long long W;
    scanf("%lld",&W);
    long long A;
    scanf("%lld",&A);
    long long B;
    scanf("%lld",&B);
    solve(H, W, A, B);
    return 0;
}
