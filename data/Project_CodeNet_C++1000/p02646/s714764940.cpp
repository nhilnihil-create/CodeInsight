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
const string YES = "YES";
const string NO = "NO";

void solve(long long A, long long V, long long B, long long W, long long T){
    if(V <= W){cout<<NO<<endl; return;}
    if(abs(B-A) > T*(V-W)){cout<<NO<<endl; return;}
    cout<<YES<<endl;
}
int main(){
    long long A;
    scanf("%lld",&A);
    long long V;
    scanf("%lld",&V);
    long long B;
    scanf("%lld",&B);
    long long W;
    scanf("%lld",&W);
    long long T;
    scanf("%lld",&T);
    solve(A, V, B, W, T);
    return 0;
}
