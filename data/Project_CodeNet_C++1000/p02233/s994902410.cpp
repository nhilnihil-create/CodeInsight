#include <bits/stdc++.h>
#define FOR(i, a, b) for(int i = (a); i < (b); ++i)
#define REP(i, n) for(int i = 0; i < (n); ++i)
#define SORT(v) sort(v.begin(), v.end());
#define pb(a) push_back(a)
using ll = long long;
using namespace std;

ll dp[50];

ll fib(ll k){
    if(dp[k] != -1){
        return dp[k];
    }else if(k == 0){
        dp[k] = 1;
        return dp[k];
    }else if(k == 1){
        dp[k] = 1;
        return dp[k];
    }else{
        dp[k] = fib(k - 1) + fib(k - 2);
        return dp[k];
    }
}


signed main(){
    REP(i, 50){
        dp[i] = -1;
    }
    ll n;
    cin >> n;
    cout << fib(n) << endl;
    return 0;
}