#include <bits/stdc++.h>
#include <stdio.h>
#include <math.h>
using namespace std;
using vi = vector<int>;
using vll = vector<long long int>;
using vc = vector<char>;
using vb = vector<bool>;
using vvi = vector<vector<int>>;
using vvll = vector<vector<long long int>>;
using ll = long long int;

ll mod = 1000000007;

int main(){
    string s; cin >> s; ll N = s.size();
    vector<char> S(N+1); 
    S[0] = 0;
    for(int i=1; i<N+1; i++){
        S[i] = s[i-1];
    }
    vi powmod(N+1);
    powmod[1] = 1;
    for(int i=2; i<N+1; i++){
        powmod[i] = (powmod[i-1]*10)%13;
    }
    ll dp[N+1][16];
    for(int i=1; i<N+1; i++){
        for(int j=0; j<13; j++){
            dp[i][j] = 0;
        }
    }
    if(S[1]=='?'){
        for(int j=0; j<10; j++){
            ll h = (j*powmod[N])%13;
            dp[1][h]++;
        }
    }else{
        int v = S[1] - '0';
        ll c = (v*powmod[N])%13;
        dp[1][c] = 1;
    }
    for(int i=2; i<N+1; i++){
        if(S[i]=='?'){
        for(int j=0; j<13; j++){
            for(int k=0; k<10; k++){
                ll h = (k*powmod[N-i+1])%13;
                ll t = dp[i][j];
                t += dp[i-1][(j-h+13)%13];
                dp[i][j] = t;
            }
            dp[i][j] %= mod;
        }
        }else{
            int g = S[i] - '0';
            int f = (g*powmod[N-i+1])%13;
            for(int j=0; j<13; j++){
                dp[i][(j+f)%13]=dp[i-1][j];
                dp[i][j] %= mod;
            }
        }
    }
    cout << dp[N][5];
}