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

ll LCSubstr(string str, string tar){
    ll res = 0;
    ll Ns = str.length(), Nt = tar.length();
    ll s=0, t=0;
    while(s < Ns){
        if(str[s]!= tar[0]){
            t = ++s;
            continue;
        }
        while( t - s <= Nt && t < Ns){
            if(str[t] == tar[t - s])
                t++;
            else
                break;
        }
        //* Now [s, t) is good
        res = max(res, t - s);
        s = t;
    }
    return res;
}

void solve(long long N, std::string S){
    ll ans = 0;
    vector<vll> dp(N, vll(N, 0));
    dp[N-1][N-1] = 1;
    for(ll i = N -1; i >= 0; i--){
        for(ll j = N-1; j >= 0; j--){
            if(S[i] != S[j]) continue;
            if(i== N-1 && j == N-1) continue;
            if(i < N-1 && j == N-1){
                dp[i][j] = 1;
            } else if(j < N-1 && i == N-1){
                dp[i][j] = 1;
            } else{
                dp[i][j] = dp[i+1][j+1] + 1;
            }
        }
    }
    REP(i, N){
        REP(j, N){
            ans = max(ans, min(dp[i][j], abs(i-j)));
        }
    }
    cout<<ans<<endl;
}

int main(){
    long long N;
    scanf("%lld",&N);
    std::string S;
    std::cin >> S;
    solve(N, S);
    return 0;
}
