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
const string YES = "Yes";
const string NO = "No";
ll gK;
bool isGood = false;
void solve(long long A, long long B, long long C, ll K){
    if(A < B && B < C) {
        isGood = true;
        return;
    }
    if(K == 0)  return;
    solve(A*2, B, C, K-1);
    solve(A, B*2, C, K-1);
    solve(A, B, C*2, K-1);
}
int main(){
    long long A;
    scanf("%lld",&A);
    long long B;
    scanf("%lld",&B);
    long long C;
    scanf("%lld",&C);
    scanf("%lld",&gK);
    solve(A, B, C, gK);
    if(isGood) cout<<YES<<endl;
    else cout<<NO<<endl;
    return 0;
}
