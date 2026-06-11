#include <iostream>
#include <string>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

const long long INF = 1LL << 60;

long long teisu = 998244353;
unsigned long long dp[3000][3001];

int main(){

    int N, S;
    cin >> N >> S;
    int arr[N];

    for  (int i = 0; i < N ;++i){
        cin >> arr[i];
        for (int j=0; j < S+1; ++j){
            dp[i][j] = 0;
        }
    }

//    for (int i=0; i < teisu; ++i){
//        if (arr[0]==i){
//            dp[0][i] = 1;
//        }
//    }
    dp[0][arr[0]] = 1;
    dp[0][0] = 2;

    for  (int i = 1; i < N ;++i){
        for (int j=0; j < S+1; ++j){
            if(j-arr[i]>=0){
                dp[i][j] += dp[i-1][j-arr[i]];
                dp[i][j]%=teisu;
            }
            dp[i][j] += 2*dp[i-1][j];
            dp[i][j]%=teisu;
        }    
    }

    cout << dp[N-1][S] << endl;
    return 0;
}