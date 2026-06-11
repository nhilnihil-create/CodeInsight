#include <bits/stdc++.h>
#include <algorithm>
#include <iostream>
#include <stack>
#include <queue>
#include <cmath>
#include <string>
#include <iterator>
#include <map>
#include <set>
#include <iomanip>
#include <vector>
using namespace std;
using ll = long long;
using ld = long double;
using P = pair<ll, ll>;
using Graph = vector<vector<int>>;
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};
#define rep(i, N) for(int i = 0; i < N; i++)
#define rep2(i, l, r) for (ll i = (ll)l; i < (ll)(r); i++)
#define INF 1000000000000000000
#define MAX 200001
#define MOD 1000000007

template <typename T > inline string toString(const T &a) {ostringstream oss; oss << a; return oss.str();};

int main(){
    string s;
    cin >> s;
    ll m[] = {1, 10, 9, 12, 3, 4};
    reverse(s.begin(), s.end());
    vector<vector<ll>> dp(s.size() + 1, vector<ll>(13, 0));
    if(s[0] == '?'){
        for(int i = 0; i < 10; i++) dp[0][i] = 1;
    }
    else{
        ll D = s[0] - '0';
        dp[0][D] = 1;
    }
    for(int i = 1; i < s.size(); i++){
        if(s[i] == '?'){
            for(int j = 0; j < 10; j++){
                int amari = j * m[i % 6] % 13;
                for(int k = 0; k < 13; k++){
                    dp[i][(k + amari) % 13] += dp[i - 1][k];
                    dp[i][(k + amari) % 13] %= MOD;
                }
            }
        }
        else{
            int D = s[i] - '0';
            ll amari = D * m[i % 6] % 13;
            for(int j = 0; j < 13; j++){
                dp[i][(j + amari) % 13] += dp[i - 1][j];
                dp[i][(j + amari) % 13] %= MOD;
            } 
        }
    }
    cout << dp[s.size()-1][5] << endl;
}