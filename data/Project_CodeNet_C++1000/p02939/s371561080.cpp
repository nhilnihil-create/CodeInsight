#include <bits/stdc++.h>
#include <vector>
#include <iostream>
#include <map>
#include <cmath>
#include <string>
#include <algorithm>
#include <math.h>
using namespace std;

#define rep(i, o) for (int i = 0; i < (o);i++)
#define REP(i,a,b)for(int i=(int)(a);(i)<(int)(b);i++)
#define NUM 1e5

typedef long long ll;
typedef unsigned long long ull;

ll gcd(ll a, ll b) { return b ? gcd(b, a%b) : a; }
ll lcm(ll c, ll d) { return c / gcd(c, d) * d; }


template<class T>
bool chmax(T &a, const T &b) {
    if (a < b)
    {
        a = b;
        return 1;
    }
    return 0; 
}

template<class T>
bool chmin(T &a, const T &b) {
    if (a > b)
    {
        a = b;
        return 1;
    }
    return 0; 
}

int main() {
    string s;
    cin >> s;

    int dp[s.size()+1][3];
    memset(dp, 0, sizeof(dp));
    /* dp[i][j] で 
    1.i文字目まで見たか, 
    2.前の文字の長さが j 文字の時  を表現*/
    dp[1][0] = dp[2][1] = 1;
    rep(i, s.size()+1) {
        if (i >= 1 && s[i-1] != s[i])
        {
            chmax(dp[i+1][1], dp[i][1]+1);
        }
        if (i >= 2 && (s[i-2] != s[i] || s[i-1] != s[i+1]))
        {
            chmax(dp[i+2][2], dp[i][2]+1);
        }
        chmax(dp[i+2][2], dp[i][1] + 1); // 1 -> 2
        chmax(dp[i+1][1], dp[i][2] + 1); // 2 -> 1
        // rep(i, s.size() + 1) {
            // cout << dp[i][1] << " " << dp[i][2] << endl;
        // }
    }
    cout << max(dp[s.size()][1], dp[s.size()][2]) << endl;
    return 0;
}