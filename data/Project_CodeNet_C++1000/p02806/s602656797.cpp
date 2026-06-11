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


void solve(long long N, std::vector<std::string> s, std::vector<long long> t, std::string X){
    vll sum(N+1, 0);
    ll ans = 0;
    bool start = false;
    REP(i, N) {
        if(start){
            ans += t[i];
        }
        if(!start && s[i] == X){
            start = true;
        }
    }
    cout<<ans<<endl;

    
}

int main(){
    long long N;
    scanf("%lld",&N);
    std::vector<std::string> s(N);
    std::vector<long long> t(N);
    for(int i = 0 ; i < N ; i++){
        std::cin >> s[i];
        scanf("%lld",&t[i]);
    }
    std::string X;
    std::cin >> X;
    solve(N, std::move(s), std::move(t), X);
    return 0;
}
